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
///   Date: 6/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_VEDERE_MAINWINDOW_HPP
#define _XOS_APP_GUI_QT_VEDERE_MAINWINDOW_HPP

#include "xos/app/gui/qt/MainWindow.hpp"
#include "xos/graphic/image/surface/shape/filled_circle.hpp"
#include "xos/graphic/image/surface/shape/filled_ellipse.hpp"
#include "xos/graphic/image/surface/qt/color.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace vedere {

typedef qt::MainWindowtImplements MainWindowtImplements;
typedef qt::MainWindow MainWindowtExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = MainWindowtImplements, class TExtends = MainWindowtExtends>

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
    MainWindowt(const MainWindowt &copy): plot_(0), paint_(0) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }
    
private:
    void construct() {
    }
    void destruct() {
    }

protected:
    typedef void (derives::*plot_t)
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r);
    
    virtual void plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h) {
        int border = this->border(), borders = border + border;

        if ((borders < w) && (borders < h)) {
            int r = ((w -= borders) > (h -= borders))?(h):(w);
            plot_t plot = this->plot();
            if ((plot)) {
                (this->*plot)(im, x,y, w-borders,h-borders, r);
            }
        }        
    }
    virtual void fill_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.fill(x-w,y-h, w+w,h+h);
    }
    virtual void fill_circle_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.fill_circle(x,y, r);
    }
    virtual void fill_ellipse_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.fill_ellipse(x,y, w,h);
    }
    virtual void draw_ellipse_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.draw_ellipse(x,y, w,h);
    }
    virtual void draw_circle_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.draw_circle(x,y, r);
    }
    virtual void draw_plot
    (graphic::image::surface::area::interface& im, int x, int y, int w, int h, int r) {
        im.draw(x-w,y-h, x+w,y+h);
    }
    virtual plot_t switch_plot() {
        if (&derives::fill_plot == (plot())) {
            plot_ = &derives::fill_circle_plot;
        } else {
            if (&derives::fill_circle_plot == (plot())) {
                plot_ = &derives::fill_ellipse_plot;
            } else {
                if (&derives::fill_ellipse_plot == (plot())) {
                    plot_ = &derives::draw_ellipse_plot;
                } else {
                    if (&derives::draw_ellipse_plot == (plot())) {
                        plot_ = &derives::draw_circle_plot;
                    } else {
                        if (&derives::draw_circle_plot == (plot())) {
                            plot_ = &derives::draw_plot;
                        } else {
                            plot_ = &derives::fill_plot;
                            switch_paint();
                        }
                    }
                }
            }
        }
        return plot_;
    }
    virtual plot_t plot() const {
        if (!(plot_)) {
            return &derives::fill_plot;
        }
        return plot_;
    }

protected:
    typedef void (derives::*paint_t)
    (graphic::image::surface::area::interface& im, 
     graphic::image::surface::shape::interface& px, int x, int y, int w, int h);

    virtual void paint
    (graphic::image::surface::area::interface& im, 
     graphic::image::surface::shape::interface& px, int x, int y, int width, int height) {
        paint_t paint = 0;
        if ((paint = this->paint())) {
            (this->*paint)(im,px, x,y, width,height);
        }
    }
    virtual void color_paint
    (graphic::image::surface::area::interface& im, 
     graphic::image::surface::shape::interface& px, int x, int y, int width, int height) {
        graphic::image::interface* prevSelected = 0;

        prevSelected = im.select_image(&px);
        this->plot(im, x,y, width,height);
        im.select_image(prevSelected);
    }
    virtual void circle_paint
    (graphic::image::surface::area::interface& im, 
     graphic::image::surface::shape::interface& px, int x, int y, int width, int height) {
        size_t border = this->border(), r = (border>10)?(border):(10);
        graphic::image::surface::shape::filled_circle shape(im, px, r);
        graphic::image::interface* prevSelected = 0;

        prevSelected = im.select_image(&shape);
        this->plot(im, x,y, width,height);
        im.select_image(prevSelected);
    }
    virtual void ellipse_paint
    (graphic::image::surface::area::interface& im, 
     graphic::image::surface::shape::interface& px, int x, int y, int width, int height) {
        size_t border = this->border(), rx = (border>10)?(border):(10), ry = (rx*3)/4;
        graphic::image::surface::shape::filled_ellipse shape(im, px, rx, ry);
        graphic::image::interface* prevSelected = 0;

        prevSelected = im.select_image(&shape);
        this->plot(im, x,y, width,height);
        im.select_image(prevSelected);
    }
    virtual plot_t switch_paint() {
        if (&derives::color_paint == (paint())) {
            paint_ = &derives::circle_paint;
        } else {
            if (&derives::circle_paint == (paint())) {
                paint_ = &derives::ellipse_paint;
            } else {
                paint_ = &derives::color_paint;
            }
        }
        return plot_;
    }
    virtual paint_t paint() const {
        if (!(paint_)) {
            return &derives::color_paint;
        }
        return paint_;
    }

protected:
    virtual void onButtonRelease(const QPoint& pos) {
        this->switch_plot();
    }
    virtual void paintEvent(QPaintEvent* event) {
        QMainWindow* qMainWindow = 0;

        if ((qMainWindow = this)) {
            int width = qMainWindow->width(), height = qMainWindow->height(), x = 0, y = 0;

            if ((2 <= (x = width/2)) && (2 <= (y = height/2))) {
                size_t red = this->fg_color_red(), green = this->fg_color_green(), blue = this->fg_color_blue();
                graphic::image::surface::qt::context gc(qMainWindow);
                graphic::image::surface::qt::area im(gc);
                graphic::image::surface::qt::color px(im, red, green, blue);
                this->paint(im, px, x,y, x,y);
            }
        }
    }

protected:
    plot_t plot_;
    paint_t paint_;
};
typedef MainWindowt<> MainWindow;

} /// namespace vedere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_VEDERE_MAINWINDOW_HPP 
