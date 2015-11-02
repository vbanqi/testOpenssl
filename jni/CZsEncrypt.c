/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "CZsEncrypt.h"
#include "app_dex_encrypt.h"
/* Header for class CZsEncrypt */
typedef char BYTE;
/*
 * Class:     CZsEncrypt
 * Method:    d
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_vbanqi_encrypt_Encrypt_decrypt(JNIEnv * env, jclass clazz, jbyteArray byarray, jint offset,jint len){
        // jsize len  = (*env)->GetArrayLength(env,byarray);

        jbyte *jbarray = (jbyte *)safe_malloc(len * sizeof(jbyte));
        
        (*env)->GetByteArrayRegion(env,byarray,offset,len,jbarray);
        
        BYTE *dDate=(BYTE*)jbarray;
        
        DATA_B b;
        b.data=dDate;
        b.len=len;
        DATA_B* O_buf =decryptByte(&b);
        
        jbyteArray RtnArr =(*env)->NewByteArray(env,O_buf->len);
        (*env)->SetByteArrayRegion(env,RtnArr, 0, O_buf->len, (jbyte*)O_buf->data );
        
        safe_free(jbarray);
        safe_free(O_buf->data);
        safe_free(O_buf);
        return RtnArr;
    }

/*
 * Class:     CZsEncrypt
 * Method:    e
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_vbanqi_encrypt_Encrypt_encrypt(JNIEnv * env, jclass clazz, jbyteArray byarray, jint offset,jint len){
        // jsize len  = (*env)->GetArrayLength(env,byarray);

        jbyte *jbarray = (jbyte *)safe_malloc(len * sizeof(jbyte));
        
        (*env)->GetByteArrayRegion(env,byarray,offset,len,jbarray);
        
        BYTE *dDate=(BYTE*)jbarray;
        
        DATA_B b;
        b.data=dDate;
        b.len=len;
        DATA_B* O_buf =encryptByte(&b);
        
        jbyteArray RtnArr =(*env)->NewByteArray(env,O_buf->len);
        (*env)->SetByteArrayRegion(env,RtnArr, 0, O_buf->len, (jbyte*)O_buf->data );
        
        safe_free(jbarray);
        safe_free(O_buf->data);
        safe_free(O_buf);

        return RtnArr;
    }