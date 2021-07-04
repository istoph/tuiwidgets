#include "ZWindowFacet.h"
#include "ZWindowFacet_p.h"

TUIWIDGETS_NS_START

ZWindowFacet::ZWindowFacet() {
}

ZWindowFacet::ZWindowFacet(std::unique_ptr<ZWindowFacetPrivate> pimpl)
    : tuiwidgets_pimpl_ptr(move(pimpl))
{
}

ZWindowFacet::~ZWindowFacet() {
}

TUIWIDGETS_NS_END