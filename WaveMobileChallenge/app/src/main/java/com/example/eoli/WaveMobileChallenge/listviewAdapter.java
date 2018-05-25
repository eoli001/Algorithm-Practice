package com.example.eoli.WaveMobileChallenge;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.text.NumberFormat;
import java.util.ArrayList;

//Adapter used by listview to populate texview objects
public class listviewAdapter extends ArrayAdapter<Item> {
    public listviewAdapter(Context context, ArrayList<Item> items) {
        super(context, R.layout.item_layout, items);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for the given position
        Item item = getItem(position);

        // Inflate the view if not used
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.item_layout, parent, false);
        }
        // Use id to look up textview for data population
        TextView tvName = (TextView) convertView.findViewById(R.id.txtName);
        TextView tvPrice = (TextView) convertView.findViewById(R.id.txtPrice);

        // Use formater to format the price
        NumberFormat formater = NumberFormat.getCurrencyInstance();

        // Using the values of objects to populate data
        tvName.setText(item.product_name);
        tvPrice.setText(formater.format(Double.parseDouble(item.product_price)));

        // Return the view that has been converted
        return convertView;
    }
}
