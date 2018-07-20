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
///   File: Renderer.hpp
///
/// Author: $author$
///   Date: 7/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_VEDERE_IMAGE_RENDERER_HPP
#define _XOS_APP_GUI_QT_VEDERE_IMAGE_RENDERER_HPP

#include "xos/app/gui/vedere/image/renderer.hpp"
#include "xos/gui/qt/Qt.hpp"
#include "xos/base/to_string.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace vedere {
namespace image {

typedef QImage::Format format_t;
static const format_t format = QImage::Format_ARGB32;

typedef Qt::AspectRatioMode aspect_t;
static const aspect_t aspectIgnore = Qt::IgnoreAspectRatio;
static const aspect_t aspectKeep = Qt::KeepAspectRatio;
static const aspect_t aspect = Qt::IgnoreAspectRatio;

typedef Qt::TransformationMode transform_t;
static const transform_t transformFast = Qt::FastTransformation;
static const transform_t transformSmooth = Qt::SmoothTransformation;
#if defined(MACOSX)
static const transform_t transform = Qt::FastTransformation;
#else /// defined(MACOSX)
static const transform_t transform = Qt::SmoothTransformation;
#endif /// defined(MACOSX)
        
typedef gui::vedere::image::renderert
<image::format_t, image::format,
 image::aspect_t, image::aspect,
 image::transform_t, image::transform> renderer_implements;

typedef gui::vedere::image::renderer_extendt<renderer_implements> renderer_extends;

///////////////////////////////////////////////////////////////////////
///  Class: Renderer
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Renderer
: virtual public renderer_implements, public renderer_extends {
public:
    typedef renderer_implements implements;
    typedef renderer_extends extends;

    Renderer(QWidget* widget)
    : widget_(widget), 
      imageAspect_(image::aspect), imageTransform_(image::transform) {
    }
    Renderer(const Renderer& copy)
    : widget_(copy.widget()), 
      imageAspect_(copy.aspect()), imageTransform_(copy.transform()) {
    }
    Renderer()
    : widget_(0), 
      imageAspect_(image::aspect), imageTransform_(image::transform) {
    }
    virtual ~Renderer() {
    }

    virtual bool init(QWidget* widget) {
        widget_ = widget;
        return true;
    }
    virtual bool finish() {
        widget_ = 0;
        return true;
    }

    using extends::render;
    virtual bool render
    (const void* image, size_t image_width, size_t image_height,
     size_t width, size_t height, size_t x, size_t y, 
     image::format_t image_format, image::aspect_t image_aspect, image::transform_t image_transform) {
        if ((widget_) && (image)) {
            QPainter qPainter(widget_);
            QImage qImage
            ((const unsigned char*)(image),
             image_width, image_height, image_format);
            qPainter.drawImage
            (x,y, qImage.scaled(width, height, image_aspect, image_transform));
            return true;
        }
        return false;
    }

    virtual image::aspect_t aspect() const {
        return imageAspect_;
    }

    virtual bool transform_smooth(bool on = true) {
        if ((on)) {
            imageTransform_ = image::transformSmooth;
        } else {
            imageTransform_ = image::transformFast;
        }
        return on;
    }
    virtual image::transform_t transform() const {
        return imageTransform_;
    }

    virtual QWidget* widget() const {
        return (QWidget*)widget_;
    }

protected:
    QWidget* widget_;
    image::aspect_t imageAspect_;
    image::transform_t imageTransform_;
};

} /// namespace image
} /// namespace vedere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_VEDERE_IMAGE_RENDERER_HPP 
