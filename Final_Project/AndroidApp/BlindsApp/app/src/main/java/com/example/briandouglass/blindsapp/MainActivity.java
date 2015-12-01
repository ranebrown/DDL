package com.example.briandouglass.blindsapp;

import java.util.Calendar;

import android.os.Bundle;
import android.view.View;
import android.app.Activity;
import android.content.Intent;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.TimePicker.OnTimeChangedListener;


import app.akexorcist.bluetotohspp.library.BluetoothSPP;
import app.akexorcist.bluetotohspp.library.BluetoothState;
import app.akexorcist.bluetotohspp.library.DeviceList;




public class MainActivity extends Activity {
    BluetoothSPP bt;
    Button btButton;
    Button oTimeSetButton;
    Button cTimeSetButton;
    TextView timePickView;
    TimePicker timePick;
    SeekBar theSeekBar;
    ProgressBar theProgressBar;
    String time = "0000";
    String xtime = "";
    String level= "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        //Default stuff
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);



        theSeekBar = (SeekBar) findViewById(R.id.setLevelSeekBar);
        theSeekBar.setOnSeekBarChangeListener(seekBarListener);
        theProgressBar = (ProgressBar) findViewById(R.id.progressBar);

        timePick = (TimePicker) findViewById(R.id.timePickerWidget);
        timePickView = (TextView) findViewById(R.id.timeView);

        oTimeSetButton = (Button) findViewById(R.id.openTimeSetter);
        cTimeSetButton = (Button) findViewById(R.id.closeTimeSetter);

        //Bluetooth stuff
        final Button connect = (Button)findViewById(R.id.btConnectButton);
        connect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                connect();
            }
        });

        oTimeSetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                xtime = "";
                xtime = "o" + time;
                timePickView.setText(xtime);
                //bt.send(xtime);
            }
        });
        cTimeSetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                xtime = "";
                xtime = "c" + time;
                timePickView.setText(xtime);
                //bt.send(xtime);
            }
        });



        Calendar now = Calendar.getInstance();
        timePick.setCurrentHour(now.get(Calendar.HOUR_OF_DAY));
        timePick.setCurrentMinute(now.get(Calendar.MINUTE));
        timePick.setOnTimeChangedListener(new OnTimeChangedListener() {

            @Override
            public void onTimeChanged(TimePicker view, int hourOfDay, int minute) {

                time = "";
                if (hourOfDay < 10) {
                    time = time + "0" + hourOfDay;
                }
                else {
                    time = time + hourOfDay;
                }


                if (minute < 10) {
                    time = time + "0" + minute;
                }
                else {
                    time = time + minute;
                }

            }
        });

    }//onCreate

    private SeekBar.OnSeekBarChangeListener seekBarListener = new SeekBar.OnSeekBarChangeListener(){

        @Override
        public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
            //When the level on the seek bar has changed, send the level to the window

            if (Integer.toString(progress).length() == 2)
            {
                level = "p" + "00" + progress;
            }
            else if (Integer.toString(progress).length() == 1)
            {
                level = "p" + "000" + progress;
            }
            else
            {
                level = "p" + "0" + progress;
            }
            timePickView.setText(level);
            theProgressBar.setProgress(progress);
            bt.send(level, false);
        }
        @Override
        public void onStartTrackingTouch(SeekBar seekBar) {}
        @Override
        public void onStopTrackingTouch(SeekBar seekBar) {}
    };

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
                int i;
                for(i=0;i<5;i=i+1) connect(); //Try to reconnect 5 times
            }

            public void onDeviceConnectionFailed() {
                btButton.setText("Failed to Connect");
                // Do something when connection failed
            }
        });

        bt.setOnDataReceivedListener(new BluetoothSPP.OnDataReceivedListener() {
            public void onDataReceived(byte[] data, String message) {
                if(data[0] == 'r'){
                    timePickView.setText("rx'd:" + data);
                }
                else{
                    theProgressBar.setProgress(data[1]);
                    timePickView.setText(data[1]);
                }
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



/*    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }*/
