// Copyright (c) 2014-2018 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#include <xlnt/worksheet/worksheet.hpp>

#include <detail/implementations/cell_impl.hpp>

namespace xlnt {
namespace detail {

cell_impl::cell_impl()
    : type_(cell_type::empty),
      parent_(nullptr),
      column_(1),
      row_(1),
      is_merged_(false),
      value_numeric_(0)
{
}

cell_impl::cell_impl(const cell_impl &other)
{
    type_ = other.type_;
    parent_ = other.parent_;
    column_ = other.column_;
    row_ = other.row_;
    is_merged_ = other.is_merged_;
    value_text_ = other.value_text_;
    value_numeric_ = other.value_numeric_;
    formula_ = other.formula_;
    hyperlink_ = other.hyperlink_;
    format_ = other.format_;
    comment_ = other.comment_;

    if (format_.is_set())
    {
        format_.get()->references++;
    }
}

cell_impl &cell_impl::operator=(const cell_impl &other)
{
    if (format_.is_set())
    {
        format_.get()->references--;
    }
	
    type_ = other.type_;
    parent_ = other.parent_;
    column_ = other.column_;
    row_ = other.row_;
    is_merged_ = other.is_merged_;
    value_text_ = other.value_text_;
    value_numeric_ = other.value_numeric_;
    formula_ = other.formula_;
    hyperlink_ = other.hyperlink_;
    format_ = other.format_;
    comment_ = other.comment_;

    if (format_.is_set())
    {
        format_.get()->references++;
    }

	return *this;
}

} // namespace detail
} // namespace xlnt
