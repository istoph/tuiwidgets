#include "ZTest.h"

#include <Tui/ZEvent.h>
#include <Tui/ZTerminal.h>
#include <Tui/ZWidget.h>
#include <Tui/ZImage.h>

#include <QCoreApplication>

TUIWIDGETS_NS_START

namespace ZTest {

    TUIWIDGETS_EXPORT void sendText(ZTerminal *terminal, QString text, Qt::KeyboardModifiers modifiers) {
        Tui::ZKeyEvent event(Qt::Key_unknown, modifiers, text);
        terminal->dispatchKeyboardEvent(event);
    }

    TUIWIDGETS_EXPORT void sendKey(ZTerminal *terminal, Qt::Key key, Qt::KeyboardModifiers modifiers) {
        Tui::ZKeyEvent event(key, modifiers, {});
        terminal->dispatchKeyboardEvent(event);
    }

    TUIWIDGETS_EXPORT void sendKeyToWidget(Tui::ZWidget *w, Qt::Key key, Qt::KeyboardModifiers modifiers) {
        Tui::ZKeyEvent event(key, modifiers, {});
        w->event(&event);
    }

    TUIWIDGETS_EXPORT ZImage waitForNextRenderAndGetContents(ZTerminal *terminal) {

        std::unique_ptr<ZImage> result;

        QMetaObject::Connection connection =
                QObject::connect(terminal, &Tui::ZTerminal::afterRendering, terminal,
                                 [&result, terminal] {
            result = std::make_unique<ZImage>(terminal->grabCurrentImage());
        });

        while (!result) {
            QCoreApplication::processEvents(QEventLoop::AllEvents);
        }

        QObject::disconnect(connection);
        return std::move(*result);
    }

}

TUIWIDGETS_NS_END