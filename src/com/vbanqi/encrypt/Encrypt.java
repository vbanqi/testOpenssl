package com.vbanqi.encrypt;

import android.R.integer;

public class Encrypt {
	 static {
	        System.loadLibrary("endex");
	    }
	 
	public native static byte[] decrypt(byte[] data, int off, int length);
	public native static byte[] encrypt(byte[] data, int off, int length);
}
