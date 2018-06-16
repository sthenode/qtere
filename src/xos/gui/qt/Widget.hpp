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
///   File: Widget.hpp
///
/// Author: $author$
///   Date: 6/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_WIDGET_HPP
#define _XOS_GUI_QT_WIDGET_HPP

#include "xos/gui/qt/Qt.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef QWidget WidgettExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Widgett
///////////////////////////////////////////////////////////////////////
template <class TExtends = WidgettExtends>
class _EXPORT_CLASS Widgett: public TExtends {
public:
    typedef TExtends extends;

    Widgett(QWidget* parent): extends(parent) {
    }
    Widgett() {
    }
    virtual ~Widgett() {
    }
private:
    Widgett(const Widgett &copy) {
    }

public:    
    virtual QSize resizeToParent() {
        QWidget* parent = 0;
        if ((parent = this->parentWidget())) {
            this->resize(parent->size());
        }
        return this->size();
    }
    virtual bool postMessage(Message::Type type, Message::Data data = 0) {
        MessageEvent* event = 0;
        if ((event = new MessageEvent(type, data))) {

            LOG_TRACE("QApplication::postEvent(this, event)...");
            QApplication::postEvent(this, event);
        }
        return false;
    }

protected:
    virtual void mouseReleaseEvent(QMouseEvent* event) {
        extends::mouseReleaseEvent(event);
        if ((event)) {
            Qt::MouseButton button = event->button();
            QPoint pos = event->pos();

            LOG_DEBUG("...button = " << button << " x = " << pos.x() << " y = " << pos.y());
            if (Qt::RightButton == (button)) {
                onRightButtonReleaseEvent(pos, *event);
            } else {
                if (Qt::LeftButton == (button)) {
                    onLeftButtonReleaseEvent(pos, *event);
                } else {
                    onButtonReleaseEvent(pos, *event);
                }
            }
        }
    }
    virtual void onRightButtonReleaseEvent(const QPoint& pos, const QMouseEvent& event) {
        onButtonReleaseEvent(pos, event);
    }
    virtual void onLeftButtonReleaseEvent(const QPoint& pos, const QMouseEvent& event) {
        onButtonReleaseEvent(pos, event);
    }
    virtual void onButtonReleaseEvent(const QPoint& pos, const QMouseEvent& event) {
    }
    
    virtual void customEvent(QEvent* event) {
        if ((event)) {
            QEvent::Type type = event->type();
            
            LOG_TRACE("...type = " << type);
            onCustomEvent(type, *event);
        }
    }
    virtual void onCustomEvent(const QEvent::Type& type, const QEvent& event) {
        if (EventMessage == (type)) {
            onMessageEvent((const MessageEvent&)event);
        }
    }
    virtual void onMessageEvent(const MessageEvent& event) {
        onMessage(event.message().type(), event.message().data());
    }
    virtual void onMessage(const Message::Type& type, const Message::Data& data) {
    }
    
protected:
};

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_WIDGET_HPP 
