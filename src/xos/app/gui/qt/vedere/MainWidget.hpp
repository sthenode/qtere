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
///   File: MainWidget.hpp
///
/// Author: $author$
///   Date: 7/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_VEDERE_MAINWIDGET_HPP
#define _XOS_APP_GUI_QT_VEDERE_MAINWIDGET_HPP

#include "xos/app/gui/vedere/window.hpp"
#include "xos/app/gui/vedere/image/transform.hpp"
#include "xos/app/gui/qt/vedere/Renderer.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace vedere {

typedef gui::vedere::windowt
<gui::vedere::window_extendt<QWidget> > MainWidgetExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWidget
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MainWidget: public MainWidgetExtends {
public:
    typedef MainWidgetExtends extends;

    MainWidget(QWidget* parent) {
        this->setParent(parent);
    }
    MainWidget() {
    }
    virtual ~MainWidget() {
    }
private:
    MainWidget(const MainWidget &copy) {
    }

public:
    virtual bool init(gui::vedere::image::transform_t transform) {
        renderer_.init(this);
        renderer_.transform_smooth
        (!(gui::vedere::image::transform_smooth != transform));
        return true;
    }
    virtual bool finish() {
        renderer_.finish();
        return true;
    }

    virtual void* load_image
    (io::byte_reader& reader, size_t size, size_t width, size_t height) {
        return renderer_.load_image(reader, size, width, height);
    }
    virtual void* set_image
    (byte_t* bytes, size_t size, size_t width, size_t height) {
        return renderer_.set_image(bytes, size, width, height);
    }
    virtual const void* image(size_t& size, size_t& width, size_t& height) const {
        return renderer_.image(size, width, height);
    }

    virtual void switch_render() {
        renderer_.switch_render();
        update(0,0, width(),height());
    }

    virtual bool post_message(message_type_t type, message_data_t data) {
        LOG_DEBUG("QApplication::postEvent(this, new MessageQEvent(message_type_t type = " << type << ",...))...");
        QApplication::postEvent(this, new MessageQEvent(type, data));
        return false;
    }
    
protected:
    virtual void resizeEvent(QResizeEvent *event) {
        size_t width = this->width(), height = this->height();
        LOG_DEBUG("extends::resizeEvent(event)...");
        extends::resizeEvent(event);
        LOG_DEBUG("renderer_.resize(" << width << ", " << height << ")");
        renderer_.resize(width, height);
    }
    virtual void paintEvent(QPaintEvent *event) {
        extends::paintEvent(event);
        renderer_.render();
    }
    virtual void mouseReleaseEvent(QMouseEvent *event) {
        if ((event)) {
            Qt::MouseButton button = event->button();

            LOG_DEBUG("...button  = " << button);
            LOG_DEBUG("extends::mouseReleaseEvent(event)...");
            extends::mouseReleaseEvent(event);
            switch((button)) {
            case Qt::LeftButton:
                LOG_DEBUG("post_message(message_type_switch_render, 0)...");
                post_message(message_type_switch_render, 0);
                break;
            case Qt::RightButton:
                break;
            default:
                break;
            }
        } else {
            LOG_ERROR("...unexpected failed on event = " << pointer_to_string(event));
        }
    }
    virtual void customEvent(QEvent* event) {
        QEvent::Type type = event->type();
        switch(type) {
        case Message: {
            MessageQEvent* message = ((MessageQEvent*)event);
            on_message(message->type(), message->data());
            break; }
        default:
            LOG_DEBUG("...customEvent() type = " << type);
            break;
        }
    }

protected:
    enum {
        Message = QEvent::User+1
    };
    class MessageQEvent: public QEvent {
    public:
        MessageQEvent
        (message_type_t type, message_data_t data)
        : QEvent((Type)Message), message_(type, data) {
        }
        MessageQEvent
        (const MessageQEvent& copy)
        : QEvent((Type)Message), message_(copy.message_) {
        }
        virtual message_type_t type() const { 
            return message_.type_; 
        }
        virtual message_data_t data() const { 
            return message_.data_; 
        }
    protected:
        message_t message_;
    };

protected:
    Renderer renderer_;
};

} /// namespace vedere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_VEDERE_MAINWIDGET_HPP 
