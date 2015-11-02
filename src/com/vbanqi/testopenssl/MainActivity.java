package com.vbanqi.testopenssl;

import com.vbanqi.encrypt.Encrypt;

import android.app.Activity;
import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		TextView tvstr = (TextView)findViewById(R.id.tv_test_str);
		TextView tvTest = (TextView)findViewById(R.id.tv_test_result);
		String str = "dajiahao12312313dadsadadsasdasd";//原始字符串
		tvstr.setText(str);
		byte[] en = str.getBytes();
		byte[] b = Encrypt.encrypt(en, 0, en.length);//加密
		String resultString = Base64.encodeToString(b,  Base64.DEFAULT);//编码
		tvTest.setText(resultString);
		
		byte[] d = Base64.decode(resultString, Base64.DEFAULT);
		byte[] de = Encrypt.decrypt(d, 0, d.length);
		String reString = new String(de);
		
		Log.v(this.getClass().getName(), "解密后："+reString);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
