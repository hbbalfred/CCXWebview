//
//  ZYWebView.cpp
//  CCXWebview
//
//  Created by Vincent on 12-11-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "ZYWebView.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>

/*
 More info about JNI using, check this:
 http://go3k.org/?p=49
 */

#warning 如果想在你的工程中嵌入，前务必修改这个包名，值为Andriod工程Main Activity的路径
#warning If you want to use this CCXWebview in your project, please modify this packageName as your Android project.
#define  CLASS_NAME "org/go3k/ccxwebview/CCXWebview"


void initJNI()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "init", "()V"))
    {
        t.env->CallStaticObjectMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        return;
    }

    LOGD("call init fail");
}
void displayWebViewJNI(float x, float y, float width, float height)
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "displayWebView", "(IIII)V"))
    {
        jint jx = (int)x;
        jint jy = (int)y;
        jint jw = (int)width;
        jint jh = (int)height;
        t.env->CallStaticObjectMethod(t.classID, t.methodID, jx, jy, jw, jh);
        t.env->DeleteLocalRef(t.classID);
        return;
    }

    LOGD("call displayWebView fail");
}

void updateURLJNI(const char* url)
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "updateURL", "(Ljava/lang/String;)V"))
    {
        jstring jurl = t.env->NewStringUTF(url);
        t.env->CallStaticObjectMethod(t.classID, t.methodID, jurl);
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jurl);
        return;
    }

    LOGD("call updateURL fail");
}

void removeWebViewJNI()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "removeWebView", "()V"))
    {
        t.env->CallStaticObjectMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        return;
    }

    LOGD("call removeWebView fail");
}


ZYWebView::ZYWebView(){}
ZYWebView::~ZYWebView(){}

bool ZYWebView::init()
{
    return true;
}

void ZYWebView::showWebView(const char* url, float x, float y, float width, float height)
{
    initJNI();
    displayWebViewJNI(x, y, width, height);
    updateURLJNI(url);
}

void ZYWebView::updateURL(const char* url)
{
    updateURLJNI(url);
}

void ZYWebView::removeWebView()
{
    removeWebViewJNI();
}

