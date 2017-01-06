#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include "FastDelegate.h"

//typedef boost::function<void ()> ResultCallback;
//typedef boost::function<void ()> NotNeedCallback;
typedef fastdelegate::FastDelegate0<> ResultCallback;
typedef fastdelegate::FastDelegate0<> NotNeedCallback;

#endif
