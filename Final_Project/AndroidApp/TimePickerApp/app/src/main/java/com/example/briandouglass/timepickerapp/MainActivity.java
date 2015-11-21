package com.example.briandouglass.timepickerapp;

import java.util.Calendar;
import android.os.Bundle;
import android.app.Activity;

import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.TimePicker.OnTimeChangedListener;
import android.widget.Toast;

public class MainActivity extends Activity {

    TimePicker pickerTime;
    TextView info;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        info = (TextView) findViewById(R.id.info);
        pickerTime = (TimePicker) findViewById(R.id.pickertime);

        Calendar now = Calendar.getInstance();


        pickerTime.setCurrentHour(now.get(Calendar.HOUR_OF_DAY));
        pickerTime.setCurrentMinute(now.get(Calendar.MINUTE));
        pickerTime.setOnTimeChangedListener(new OnTimeChangedListener() {

            @Override
            public void onTimeChanged(TimePicker view, int hourOfDay, int minute) {
                Toast.makeText(getApplicationContext(),
                        "onTimeChanged", Toast.LENGTH_SHORT).show();

                info.setText(
                        "Hour of Day: " + hourOfDay + "\n" +
                                "Minute: " + minute);
            }
        });
    }

}