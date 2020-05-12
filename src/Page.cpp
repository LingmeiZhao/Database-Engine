#include "Page.h"

Page::Page(std::ofstream &stream, int pageNumber)
    : stream{stream}, startPos{pageNumber * pageSize} {}
