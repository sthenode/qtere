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
///   File: MainWindow.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_LAMNA_MAINWINDOW_HPP
#define _XOS_APP_GUI_QT_LAMNA_MAINWINDOW_HPP

#include "xos/gui/qt/application/MainWindow.hpp"
#include "xos/graphic/surface/filled_circle.hpp"
#include "xos/graphic/surface/qt/color.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace lamna {

typedef implement_base MainWindowImplements;
typedef xos::gui::qt::application::MainWindow MainWindowtExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = MainWindowImplements, class TExtends = MainWindowtExtends>

class _EXPORT_CLASS MainWindowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef MainWindowt derives;

    MainWindowt(): plot_(0), paint_(0) {
        construct();
    }
    virtual ~MainWindowt() {
        destruct();
    }
private:
    MainWindowt(const MainWindowt &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }
    
public:
    virtual bool afterCreate
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        bool result = true;
        return result;
    }
    virtual bool beforeDestroy
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        bool result = true;
        return result;
    }
    
protected:
    typedef void (derives::*plot_t)
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r);
    
    virtual void plot
    (graphic::surface::image_interface& im, int x, int y, int w, int h) {
        int border = this->border(), borders = border + border;

        if ((borders < w) && (borders < h)) {
            int r = ((w -= borders) > (h -= borders))?(h):(w);
            plot_t plot = this->plot();
            if ((plot)) {
                (this->*plot)(im, x,y, w-borders,h-borders, r);
            } else {
                this->draw(im, x,y, w-borders,h-borders, r);
            }
        }        
    }
    virtual void draw
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.draw(x-w,y-h, x+w,y+h);
        im.draw(x-w,y+h, x+w,y-h);
    }
    virtual void fill
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.fill(x-w,y-h, w+w,h+h);
    }

    virtual void draw_circle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.draw_circle(x,y, r);
    }
    virtual void fill_circle
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.fill_circle(x,y, r);
    }

    virtual void draw_ellipse
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.draw_ellipse(x,y, w,h);
    }
    virtual void fill_ellipse
    (graphic::surface::image_interface& im, int x, int y, int w, int h, int r) {
        im.fill_ellipse(x,y, w,h);
    }

    virtual plot_t switch_plot() {
        if ((&derives::draw != (plot_)) && (plot_)) {
            if (&derives::fill != (plot_)) {
                if (&derives::draw_circle != (plot_)) {
                    if (&derives::fill_circle != (plot_)) {
                        if (&derives::draw_ellipse != (plot_)) {
                            plot_ = &derives::draw;
                            switch_paint();
                        } else {
                            plot_ = &derives::fill_ellipse;
                        }
                    } else {
                        plot_ = &derives::draw_ellipse;
                    }
                } else {
                    plot_ = &derives::fill_circle;
                }
            } else {
                plot_ = &derives::draw_circle;
            }
        } else {
            plot_ = &derives::fill;
        }
        return plot_;
    }
    virtual plot_t plot() const {
        if (!(plot_)) {
            return &derives::draw;
        }
        return plot_;
    }
    
    typedef void (derives::*paint_t)
    (graphic::surface::image& im, 
     graphic::surface::shape& px, int x, int y, int w, int h);

    virtual void paint
    (graphic::surface::image& im, 
     graphic::surface::shape& px, int x, int y, int width, int height) {
        paint_t paint = 0;
        if ((paint = this->paint())) {
            (this->*paint)(im,px, x,y, width,height);
        } else {
            this->color_paint(im,px, x,y, width,height);
        }
    }
    virtual void color_paint
    (graphic::surface::image& im, 
     graphic::surface::shape& px, int x, int y, int width, int height) {
        graphic::image_interface* prevSelected = 0;

        prevSelected = im.select_image(&px);
        this->plot(im, x,y, width,height);
        im.select_image(prevSelected);
    }
    virtual void circle_paint
    (graphic::surface::image& im, 
     graphic::surface::shape& px, int x, int y, int width, int height) {
        int border = this->border();
        graphic::surface::filled_circle shape(im, px, (border>5)?(border):(5));
        graphic::image_interface* prevSelected = 0;

        prevSelected = im.select_image(&shape);
        this->plot(im, x,y, width,height);
        im.select_image(prevSelected);
    }
    virtual paint_t switch_paint() {
        if (((&derives::color_paint) != (paint_)) && (paint_)) {
            paint_ = &derives::color_paint;
        } else {
            paint_ = &derives::circle_paint;
        }
        return paint_;
    }
    virtual paint_t paint() const {
        return paint_;
    }

    virtual size_t fg_color_red() const {
        size_t value = 0;
        return value;
    }
    virtual size_t fg_color_green() const {
        size_t value = 0;
        return value;
    }
    virtual size_t fg_color_blue() const {
        size_t value = 255;
        return value;
    }

    virtual int border() const {
        size_t value = 10;
        return value;
    }
    
protected:
    virtual void onMessage(const xos::gui::qt::Message::Type& type, const xos::gui::qt::Message::Data& data) {
        if (xos::gui::qt::Message::InvalidateWidget == (type)) {
            this->update();
        }
    }
    virtual void onButtonReleaseEvent(const QPoint& pos, const QMouseEvent& event) {
        this->switch_plot();
        this->postMessage(xos::gui::qt::Message::InvalidateWidget);
    }

    virtual void resizeEvent(QResizeEvent *event) {
        LOG_DEBUG("...width = " << event->size().width() << ", height = " << event->size().height());
        extends::resizeEvent(event);
    }
    virtual void paintEvent(QPaintEvent* event) {
        QMainWindow* qMainWindow = 0;

        if ((qMainWindow = this)) {
            int width = qMainWindow->width(), height = qMainWindow->height(), x = 0, y = 0;

            if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
                size_t red = this->fg_color_red(), green = this->fg_color_green(), blue = this->fg_color_blue();
                graphic::surface::qt::context gc(qMainWindow);
                graphic::surface::qt::image im(gc);
                graphic::surface::qt::color px(im, red, green, blue);
                this->paint(im, px, x,y, x,y);
            }
        }
    }

private:
    void construct() {
    }
    void destruct() {
    }

protected:
    plot_t plot_;
    paint_t paint_;
};
typedef MainWindowt<> MainWindow;

} /// namespace lamna
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_LAMNA_MAINWINDOW_HPP 
