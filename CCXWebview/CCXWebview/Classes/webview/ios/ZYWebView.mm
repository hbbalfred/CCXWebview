//
//  ZYWebView.cpp
//  CCXWebview
//
//  Created by Vincent on 12-11-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "ZYWebView.h"
#import "ZYWebView_iOS.h"

static ZYWebView_iOS* m_webViewiOS;

ZYWebView::ZYWebView()
{
    
}

ZYWebView::~ZYWebView()
{
    [m_webViewiOS release];
    m_webViewiOS = NULL;
}

bool ZYWebView::init()
{
	return true;
}

void ZYWebView::showWebView(const char* url, float x, float y, float width, float height)
{
    m_webViewiOS = [[ZYWebView_iOS alloc] init];
	
    // get the eaglview instance here and pass it, because of
    // there is a problem of 'Member access into incomplete type'
    // when getEAGLView in ZYWebView_iOS
	auto eaglview = (CCEAGLView*)cocos2d::Director::getInstance()->getOpenGLView()->getEAGLView();
    [m_webViewiOS showWebView_x:x y:y width:width height:height eaglview:eaglview];
    
    this->updateURL(url);
}

void ZYWebView::updateURL(const char* url)
{
    [m_webViewiOS updateURL:url];
}

void ZYWebView::removeWebView()
{
    [m_webViewiOS removeWebView];
}
