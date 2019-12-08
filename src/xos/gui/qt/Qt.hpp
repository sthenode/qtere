///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Qt.hpp
///
/// Author: $author$
///   Date: 5/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_QT_HPP
#define _XOS_GUI_QT_QT_HPP

#include "xos/base/to_string.hpp"
#include "xos/io/logger.hpp"
#include <QtCore/QtCore>
#if  (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtGui/QtGui>
#else
#include <QtWidgets/QtWidgets>
#endif

namespace xos {
namespace gui {
namespace qt {

enum {
    EventMessage = QEvent::User+1
};

///////////////////////////////////////////////////////////////////////
///  Class: Message
///////////////////////////////////////////////////////////////////////
class Message {
public:
    typedef int Type;
    typedef void* Data;
    enum {
        InvalidateWidget
    };
    Message(Type type = 0, Data data = 0): type_(type), data_(data) {
    }
    Message(const Message& copy): type_(copy.type()), data_(copy.data()) {
    }
    virtual Type type() const {
        return type_;
    }
    virtual Data data() const {
        return data_;
    }
protected:
    Type type_;
    Data data_;
};

///////////////////////////////////////////////////////////////////////
///  Class: MessageEvent
///////////////////////////////////////////////////////////////////////
class MessageEvent: public QEvent {
public:
    typedef QEvent extends;
    MessageEvent(Message::Type type = 0, Message::Data data = 0)
    : extends((Type)EventMessage), message_(type, data) {
    }
    MessageEvent(const MessageEvent& copy)
    : extends((Type)EventMessage), message_(copy.message()) {
    }
    virtual ~MessageEvent() {
    }
    virtual const Message& message() const {
        return message_;
    }
protected:
    Message message_;
};

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_QT_HPP 
