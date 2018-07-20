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
///   Date: 7/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_VEDERE_RENDERER_HPP
#define _XOS_APP_GUI_QT_VEDERE_RENDERER_HPP

#include "xos/app/gui/qt/vedere/image/Renderer.hpp"
#include "xos/app/gui/vedere/renderer.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace vedere {

typedef implement_base Renderer_implements;
typedef gui::vedere::renderer_extendt
<image::Renderer::image_format_t, 
 image::Renderer::image_format_none, image::Renderer>  Renderer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: Renderer
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Renderer: virtual public Renderer_implements, public Renderer_extends {
public:
    typedef Renderer_implements implements;
    typedef Renderer_extends extends;

    Renderer(const Renderer &copy) {
    }
    Renderer() {
    }
    virtual ~Renderer() {
    }

    virtual bool init(QWidget* widget) {
        return imageRenderer_.init(widget);
    }
    virtual bool finish() {
        return imageRenderer_.finish();
    }
    virtual bool resize(size_t width, size_t height) {
        return imageRenderer_.resize(width, height);
    }
    virtual image::Renderer* image_renderer(const image_format_t& image_format) const {
        if (!(image_format != imageRenderer_.image_format())) {
            return ((image::Renderer*)&imageRenderer_);
        }
        return 0;
    }

protected:
    image::Renderer imageRenderer_;
};

} /// namespace vedere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_VEDERE_RENDERER_HPP 
