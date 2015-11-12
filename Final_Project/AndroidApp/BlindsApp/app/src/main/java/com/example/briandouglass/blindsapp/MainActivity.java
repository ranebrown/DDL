package com.example.briandouglass.blindsapp;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.app.Activity;
import android.content.Intent;
import android.bluetooth.*;
import android.widget.Button;
import android.widget.TextView;
import android.widget.AbsSeekBar;

import app.akexorcist.bluetotohspp.library.BluetoothSPP;
import app.akexorcist.bluetotohspp.library.BluetoothState;
import app.akexorcist.bluetotohspp.library.DeviceList;


public class MainActivity extends Activity {
    BluetoothSPP bt;
    Button btButton;
    TextView text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        //Default stuff
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Bluetooth stuff
        final Button connect = (Button)findViewById(R.id.btConnectButton);
        connect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                connect();
            }
        });
    }//onCreate

//    @Override
//    public boolean onCreateOptionsMenu(Menu menu) {
//        // Inflate the menu; this adds items to the action bar if it is present.
//        getMenuInflater().inflate(R.menu.menu_main, menu);
//        return true;
//    }
//    @Override
//    public boolean onOptionsItemSelected(MenuItem item) {
//        // Handle action bar item clicks here. The action bar will
//        // automatically handle clicks on the Home/Up button, so long
//        // as you specify a parent activity in AndroidManifest.xml.
//        int id = item.getItemId();
//
//        //noinspection SimplifiableIfStatement
//        if (id == R.id.action_settings) {
//            return true;
//        }
//
//        return super.onOptionsItemSelected(item);
//    }

    /*public void openLock(View view){
        bt.send("o",true);
    }//openLock

    public void closeLock(View view){
        bt.send("c",true);
    }//closeLock
    */


    public void connect()
    {
        btButton = (Button) findViewById(R.id.btConnectButton);
        bt = new BluetoothSPP(getApplicationContext());

        if(bt.isBluetoothEnabled()) {
//            bt.startService(BluetoothState.DEVICE_OTHER);
            bt.setupService();
            bt.startService(BluetoothState.DEVICE_OTHER);

            Intent intent = new Intent(getApplicationContext(), DeviceList.class);
            startActivityForResult(intent, BluetoothState.REQUEST_CONNECT_DEVICE);
        }else {
            btButton.setText("NO BLUETOOTH");
        }

        bt.setBluetoothStateListener(new BluetoothSPP.BluetoothStateListener() {
            public void onServiceStateChanged(int state) {
                if(state == BluetoothState.STATE_CONNECTED)
                    btButton.setText("Connected");
                    // Do something when successfully connected
                else if(state == BluetoothState.STATE_CONNECTING)
                    btButton.setText("Connecting");
                    // Do something while connecting
                else if(state == BluetoothState.STATE_LISTEN)
                    btButton.setText("Listening");
                    // Do something when device is waiting for connection
                else if(state == BluetoothState.STATE_NONE)
                    btButton.setText("No State/ not connected");
                // Do something when device don't have any connection
            }
        });

        bt.setBluetoothConnectionListener(new BluetoothSPP.BluetoothConnectionListener() {
            public void onDeviceConnected(String name, String address) {
                // Do something when successfully connected
                btButton.setText("Connected");
            }

            public void onDeviceDisconnected() {
                // Do something when connection was disconnected
                btButton.setText("Disconnnected");
            }

            public void onDeviceConnectionFailed() {
                btButton.setText("Failed to Connect");
                // Do something when connection failed
            }
        });

        bt.setOnDataReceivedListener(new BluetoothSPP.OnDataReceivedListener() {
            public void onDataReceived(byte[] data, String message) {

                btButton.setText("GOT DATA!");

            }
        });
    }

    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode == BluetoothState.REQUEST_CONNECT_DEVICE) {
            if(resultCode == Activity.RESULT_OK)
                bt.connect(data);
        } else if(requestCode == BluetoothState.REQUEST_ENABLE_BT) {
            if(resultCode == Activity.RESULT_OK) {
                bt.setupService();
                bt.startService(BluetoothState.DEVICE_OTHER);
//                setup();
            } else {
                // Do something if user doesn't choose any device (Pressed back)
            }
        }
    }

}//End of Class