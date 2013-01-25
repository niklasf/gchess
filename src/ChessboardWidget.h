/* This file is part of gchess.
 * Copyright (C) 2013 Niklas Fiekas <niklas.fiekas@tu-clausthal.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GCHESS_CHESSBOARDWIDGET_H
#define GCHESS_CHESSBOARDWIDGET_H

#include <gtkmm.h>

class ChessboardWidget : public Gtk::DrawingArea {
  public:
    ChessboardWidget();
    virtual ~ChessboardWidget();

  protected:
    virtual void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const;
    virtual void get_preferred_height_vfunc(int &minimum_height, int &natural_height) const;
    virtual void get_preferred_width_for_height_vfunc(int height, int& minimum_width, int& natural_width) const;
    virtual void get_preferred_height_for_width_vfunc(int width, int& minimum_height, int& natural_height) const;
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif
