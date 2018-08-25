import datetime

'''stock generator by Yolanda He'''

# formart number to two decimals
def f(num):
    if num == 0:
        return str(0)
    else:
        return str(format(float(num), '.2f'))


# convert number to string
def s(num):
    return str(num)


# use for generating new stock in stockstack
def new_append_stockstack(stockstack, curstockitem):
    s = {}
    s['stock'] = curstockitem['ticker']
    s['shares'] = curstockitem['shares']
    s['price'] = curstockitem['price']
    s['dividend'] = '0'
    s['cursellprofit'] = '0'
    s['split'] = '1'
    s['lastSplit'] = '1'
    stockstack.append(s)


#  prepare the data for the stockstack
def process_cur_stocktostockstack(curstockitem, stockstack):

    # process stock action
    if 'stock' in curstockitem:
        if any(d['stock'] == curstockitem['stock'] for d in stockstack):
            curlst = [d for d in stockstack if d['stock'] == curstockitem['stock']]
            stockstackitem = curlst[0]
            if curstockitem['dividend'] != '':
                stockstackitem['dividend'] = float(curstockitem['dividend']) * int(stockstackitem['shares'])
                stockstackitem['dividend'] = f(stockstackitem['dividend'])
            elif curstockitem['split'] != '':
                stockstackitem['price'] = float(stockstackitem['price']) / int(curstockitem['split'])
                stockstackitem['price'] = s(stockstackitem['price'])
                stockstackitem['shares'] = s(int(stockstackitem['shares']) * int(curstockitem['split']))
                stockstackitem['lastSplit'] = stockstackitem['split']
                stockstackitem['split'] = curstockitem['split']
        else:
            curstockitem['stockactionstatus'] = 'fail'

    # process action
    if 'ticker' in curstockitem:

        # stock is in the stock stack
        if any(d['stock'] == curstockitem['ticker'] for d in stockstack):
            for stockstackitem in stockstack:

                # process action
                if stockstackitem['stock'] == curstockitem['ticker']:

                    # process buy action
                    if curstockitem['action'] == 'BUY':
                        stockstackitem['price'] = (float(curstockitem['price']) * int(curstockitem['shares']) + float(
                            stockstackitem[
                                'price']) * int(stockstackitem['shares'])) / (int(curstockitem['shares']) + int(
                            stockstackitem['shares']))
                        stockstackitem['price'] = s(stockstackitem['price'])
                        stockstackitem['shares'] = s(int(curstockitem['shares']) + int(stockstackitem['shares']))

                    # process sell action
                    elif curstockitem['action'] == 'SELL':
                        if int(curstockitem['shares']) > int(stockstackitem['shares']):
                            # print ("You cannot sell more than you have." + '\n')
                            curstockitem['soldstatus'] = 'fail'
                        else:
                            stockstackitem['shares'] = s(int(stockstackitem['shares']) - int(curstockitem['shares']))
                            stockstackitem['cursellprofit'] = s(int(curstockitem['shares']) * (
                                    float(curstockitem['price']) - float(stockstackitem['price'])))

        else:
            # if it is buy action it does not necessary has to be in the stack
            if curstockitem['action'] == 'BUY':
                new_append_stockstack(stockstack, curstockitem)
            else:
                curstockitem['actionstatus'] = 'fail'
    return stockstack


# print the summary of shares for different stock,
def printbyaction(curstockitem, stockstack, samedatetranslist):
    boollstcheck = True
    count = 0  # count is used to check for whether there is at least one valid transaction
    for item in samedatetranslist:
        if 'ticker' in curstockitem:

            # if the stock name is not found in the stock stack
            if len([d for d in stockstack if d['stock'] == item['ticker']]) == 0:
                if curstockitem['action'] == 'BUY':
                    count += 1

            else:
                # if current action is not about trying to sell with more than in stock
                if 'soldstatus' not in curstockitem:
                    count += 1
        elif 'stock' in curstockitem:
            # if it is not try to do some stock actions to nonexistent stock
            if len([d for d in stockstack if d['stock'] == item['stock']]) != 0:
                count += 1
    if count != 0:
        boollstcheck = True
    else:
        boollstcheck = False
    if boollstcheck:
        temp = curstockitem['date'][:10]
        datetoPrint = datetime.datetime.strptime(temp, '%Y/%m/%d').strftime('%Y-%m-%d')
        sentencetoPrint = ""

        sentencetoPrint += "On " + datetoPrint + ", you have:" + '\n'
        dividendAmount = 0

        for i in stockstack:

            if int(i['shares']) != 0:
                sentencetoPrint += "    - " + s(i['shares']) + " shares of " + s(i['stock']) + " at $" + f(
                    i['price']) + " per share" + '\n'
            dividendAmount += float(i['dividend'])

        dividendAmount = f(dividendAmount)
        sentencetoPrint += "    - $" + dividendAmount + " of dividend income"
        print sentencetoPrint


# print all the same day transactions
def print_transaction(stockstack, newstocklistSorted, samedatetranslist):
    sentencetoPrint = ""
    for it in samedatetranslist:

        # print only if it is valid transaction
        if ('actionstatus' not in it) and ('stockactionstatus' not in it):
            if 'ticker' in it:
                curstockstack = [d for d in stockstack if d['stock'] == it['ticker']][0]
                if it['action'] == "BUY":
                    sentencetoPrint += "    - You bought " + it['shares'] + " shares of " + it[
                        'ticker'] + " at a price of $" + f(it['price']) + " per share" + '\n'

                elif it['action'] == "SELL":
                    profit = curstockstack['cursellprofit']

                    # if not a oversell action
                    if 'soldstatus' not in it:
                        if float(profit) >= 0:
                            sentencetoPrint += "    - You sold " + it['shares'] + " shares of " + it[
                                'ticker'] + " at a price of $" + f(
                                it['price']) + " per share" + " for a profit of $" + f(
                                profit) + '\n'
                        else:
                            sentencetoPrint += "    - You sold " + it['shares'] + " shares of " + it[
                                'ticker'] + " at a price of $" + f(it['price']) + " per share" + " for a loss of $" + f(
                                profit) + '\n'

                else:
                    sentencetoPrint += "    - You did " + it['action'] + " " + it['shares'] + " shares of " + it[
                        'ticker'] + " at a price of $" + f(it['price']) + " per share" + '\n'
            elif 'stock' in it:
                curstockstack = [d for d in stockstack if d['stock'] == it['stock']][0]

                # take stored shares and split data from stock stack
                stocksharesofar = curstockstack['shares']
                lastsplit = curstockstack['lastSplit']

                if it['dividend'] != '':
                    sentencetoPrint += "    - " + it['stock'] + " paid out $" + it[
                        'dividend'] + " dividend per share, and you have " + stocksharesofar + " shares"
                elif it['split'] != '':
                    sentencetoPrint += "    - " + it['stock'] + " split " + it[
                        'split'] + " to " + lastsplit + ", and you have " + stocksharesofar + " shares"
    if sentencetoPrint != "":
        print ("  Transactions:")
        print sentencetoPrint


# generate the stock log
def stock_generator(actions, stock_actions):
    stockstack = []
    newstocklist = actions + stock_actions
    newstocklistSorted = sorted(newstocklist, key=lambda k: k['date'])

    curDate = ''
    for i in newstocklistSorted:

        # list of same date transactions
        samedatetranslist = [d for d in newstocklistSorted if d['date'][:10] == i['date'][:10]]

        if curDate[:10] == i['date'][:10]:
            continue
        else:
            for it in samedatetranslist:
                stockstack = process_cur_stocktostockstack(it, stockstack)
            curDate = i['date']

            # print all stock information
            printbyaction(i, stockstack, samedatetranslist)
            print_transaction(stockstack, newstocklistSorted, samedatetranslist)


actions = [{'date': '1992/07/14 11:12:30', 'action': 'BUY', 'price': '12.3', 'ticker': 'AAPL', 'shares': '500'},
           {'date': '1992/09/13 11:15:20', 'action': 'SELL', 'price': '15.3', 'ticker': 'AAPL', 'shares': '100'},
           {'date': '1992/10/14 15:14:20', 'action': 'BUY', 'price': '20', 'ticker': 'MSFT', 'shares': '300'},
           {'date': '1992/10/17 16:14:30', 'action': 'SELL', 'price': '20.2', 'ticker': 'MSFT', 'shares': '200'},
           {'date': '1992/10/19 15:14:20', 'action': 'BUY', 'price': '21', 'ticker': 'MSFT', 'shares': '500'},
           {'date': '1992/10/23 16:14:30', 'action': 'SELL', 'price': '18.2', 'ticker': 'MSFT', 'shares': '600'},
           {'date': '1992/10/25 10:15:20', 'action': 'SELL', 'price': '20.3', 'ticker': 'AAPL', 'shares': '300'},
           {'date': '1992/10/25 16:12:10', 'action': 'BUY', 'price': '18.3', 'ticker': 'MSFT', 'shares': '500'},
           {'date': '1992/10/27 16:12:10', 'action': 'BUY', 'price': '18.3', 'ticker': 'MSFT', 'shares': '100'},
           {'date': '1992/10/27 16:12:10', 'action': 'SELL', 'price': '19.3', 'ticker': 'MSFT', 'shares': '100'},
           {'date': '1992/10/29 16:12:10', 'action': 'BUY', 'price': '19.3', 'ticker': 'LABU', 'shares': '100'},
           {'date': '1992/10/29 16:12:10', 'action': 'SELL', 'price': '19.5', 'ticker': 'LABU', 'shares': '100'},
           {'date': '1992/10/30 16:12:10', 'action': 'SELL', 'price': '19.3', 'ticker': 'AAPL', 'shares': '1200'}

           ]
stock_actions = [{'date': '1992/08/14', 'dividend': '0.10', 'split': '', 'stock': 'AAPL'},
                 {'date': '1992/09/01', 'dividend': '', 'split': '3', 'stock': 'AAPL'},
                 {'date': '1992/10/15', 'dividend': '0.20', 'split': '', 'stock': 'MSFT'},
                 {'date': '1992/10/16', 'dividend': '0.20', 'split': '', 'stock': 'ABC'},
                 {'date': '1992/10/28', 'dividend': '', 'split': '1', 'stock': 'MSFT'}]

curIII = {'date': '1992/07/14 11:12:30', 'action': 'BUY', 'price': '12.3', 'ticker': 'AAPL', 'shares': '500'}
stacklist = [{'stock': 'AAPL', 'shares': '600', 'price': '5', 'dividend': '0', 'cursellprofit': '0', 'split': '0',
              'lastSplit': '0'},
             {'stock': 'MSFT', 'shares': '200', 'price': '2.5', 'dividend': '0', 'cursellprofit': '0', 'split': '0',
              'lastSplit': '0'}]

stock_generator(actions, stock_actions)
