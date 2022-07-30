#ifndef TUIWIDGETS_ZROOT_P_INCLUDED
#define TUIWIDGETS_ZROOT_P_INCLUDED

#include <Tui/ZRoot.h>
#include <Tui/ZPainter.h>
#include <Tui/ZWidget.h>
#include <Tui/ZWidget_p.h>

#include <Tui/tuiwidgets_internal.h>

TUIWIDGETS_NS_START

class ZRootPrivate : public ZWidgetPrivate {

public:
    ZRootPrivate(ZRoot *pub);

public:
    int fillChar = Erased;
    QList<QObject*> windows;
    QPointer<ZTerminal> connectedTerminal;
};

TUIWIDGETS_NS_END

#endif // TUIWIDGETS_ZROOT_P_INCLUDED
