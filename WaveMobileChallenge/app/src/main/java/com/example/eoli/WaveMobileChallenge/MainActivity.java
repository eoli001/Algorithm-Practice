package com.example.eoli.WaveMobileChallenge;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ArrayAdapter<Item> adapter;
    ArrayList<Item> items;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ListView listView=(ListView)findViewById(R.id.listv);
        items=new ArrayList<Item>();

        //Get data from the url and parse by json object
        jsonRequest();

        //use adapter to populate listview objects
        adapter=new listviewAdapter(this, items);
        listView.setAdapter(adapter);
    }


    //json Get request for getting data
    public void jsonRequest(){

        // request queue for sending request
        RequestQueue requestQueue= Volley.newRequestQueue(this);

        // use given business id and access token to build url
        String business_id = "89746d57-c25f-4cec-9c63-34d7780b044b";
        String access_token = "6W9hcvwRvyyZgPu9Odq7ko8DSY8Nfm";
        String url_string = "https://api.waveapps.com/businesses/"+ business_id + "/products/?access_token=" + access_token;

        //  use json request to get the data of price and name and store them to array list
        JsonArrayRequest jsonArrayRequest=new JsonArrayRequest(url_string,new Response.Listener<JSONArray>(){
            public void onResponse(JSONArray jsonArray){
                Item product_item;
                for(int i=0;i<jsonArray.length();i++){
                    try {
                        product_item = new Item();
                        JSONObject jsonObject=jsonArray.getJSONObject(i);

                        //Get the name and price from the json objects
                        product_item.product_name = jsonObject.getString("name");
                        product_item.product_price = jsonObject.getString("price");

                        items.add(product_item);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
                adapter.notifyDataSetChanged();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError volleyError) {
                Log.e("Error", "Unable to parse json array");
            }
        });
        // add json array request to the request queue
        requestQueue.add(jsonArrayRequest);
    }

}
