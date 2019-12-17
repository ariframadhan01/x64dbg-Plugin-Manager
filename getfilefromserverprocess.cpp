// Copyright (c) 2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "getfilefromserverprocess.h"

GetFileFromServerProcess::GetFileFromServerProcess(QObject *parent) : QObject(parent)
{

}

void GetFileFromServerProcess::setData(QString sLink, QString sFileName)
{
    this->sLink=sLink;
    this->sFileName=sFileName;
}

void GetFileFromServerProcess::stop()
{

}

void GetFileFromServerProcess::process()
{
    QNetworkAccessManager nam;
    QNetworkRequest *pRequest=new QNetworkRequest(QUrl(sLink));
    QNetworkReply *reply=nam.get(*pRequest);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    if(reply->bytesAvailable())
    {
        reply->readAll();
    }

    delete pRequest;
}
