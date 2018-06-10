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
///   File: HBoxLayout.hpp
///
/// Author: $author$
///   Date: 6/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_HBOXLAYOUT_HPP
#define _XOS_GUI_QT_HBOXLAYOUT_HPP

#include "xos/gui/qt/Widget.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef QHBoxLayout HBoxLayoutExtends;
///////////////////////////////////////////////////////////////////////
///  Class: HBoxLayout
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS HBoxLayout: public HBoxLayoutExtends {
Q_OBJECT
public:
    typedef HBoxLayoutExtends extends;

    HBoxLayout(QWidget* parent): extends(parent) {
    }
    HBoxLayout() {
    }
    virtual ~HBoxLayout() {
    }
private:
    HBoxLayout(const HBoxLayout &copy) {
    }

protected:
};

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_HBOXLAYOUT_HPP 
