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

#include <algorithm>
#include <glibmm/i18n.h>

#include "ChessboardWidget.h"

ChessboardWidget::ChessboardWidget()
{
  // override_background_color(Gdk::RGBA("blue"));
}

ChessboardWidget::~ChessboardWidget()
{
}

bool ChessboardWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  const int width = get_allocation().get_width();
  const int height = get_allocation().get_height();

  const int padding = 15;
  const int border_size = width * 0.05;

  const int board_size = std::min(width, height) - 2 * (padding + border_size);
  const int board_offset_x = (width - board_size) / 2;
  const int board_offset_y = (height - board_size) / 2;

  const double square_size = board_size / 8.0;

  // Draw the background color.
  Gdk::Cairo::set_source_rgba(cr, get_style_context()->get_background_color());
  cr->paint();

  // Draw the squares.
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      if ((x + y) % 2 == 0)
      {
        cr->set_source_rgba(0, 0, 1, 0.5);
      }
      else
      {
        cr->set_source_rgba(1, 1, 1, 0.5);
      }
      cr->rectangle(board_offset_x + x * square_size, board_offset_y + y * square_size, square_size, square_size);
      cr->fill();
    }
  }

  // Draw the raised edge of the outer border.
  cr->set_source_rgba(1, 1, 1, 0.5);
  cr->move_to(board_offset_x - border_size, board_offset_y + board_size + border_size);
  cr->line_to(board_offset_x - border_size, board_offset_y - border_size);
  cr->line_to(board_offset_x + board_size + border_size, board_offset_y - border_size);
  cr->stroke();

  // Draw the sunken edge of the outer border.
  cr->set_source_rgba(0, 0, 0, 0.5);
  cr->move_to(board_offset_x - border_size, board_offset_y + board_size + border_size);
  cr->line_to(board_offset_x + board_size + border_size, board_offset_y + board_size + border_size);
  cr->line_to(board_offset_x + board_size + border_size, board_offset_y - border_size);
  cr->stroke();

  // Draw the sunken edge of the inner border.
  cr->set_source_rgba(0, 0, 0, 0.5);
  cr->move_to(board_offset_x, board_offset_y + board_size);
  cr->line_to(board_offset_x, board_offset_y);
  cr->line_to(board_offset_x + board_size, board_offset_y);
  cr->stroke();

  // Draw the raised edge of the inner border.
  cr->set_source_rgba(1, 1, 1, 0.5);
  cr->move_to(board_offset_x, board_offset_y + board_size);
  cr->line_to(board_offset_x + board_size, board_offset_y + board_size);
  cr->line_to(board_offset_x + board_size, board_offset_y);
  cr->stroke();

  // Draw the coordinates on the border.
  cr->set_source_rgba(0, 0, 0, 0.5);
  cr->set_font_size(0.6 * border_size);
  const char *files[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
  for (int x = 0; x < 8; x++)
  {
    Cairo::TextExtents extents;
    cr->get_text_extents(files[x], extents);
    cr->move_to(
      board_offset_x + square_size / 2.0 + x * square_size - extents.width / 2.0 - extents.x_bearing,
      board_offset_y + board_size + border_size / 2.0 - extents.height / 2.0 - extents.y_bearing);
    cr->show_text(files[x]);
  }
  const char *ranks[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
  for (int y = 0; y < 8; y++)
  {
    Cairo::TextExtents extents;
    cr->get_text_extents(ranks[y], extents);
    cr->move_to(
      board_offset_x - border_size / 2.0 - extents.width / 2.0 - extents.x_bearing,
      board_offset_y + board_size - square_size / 2.0 - y * square_size - extents.height / 2.0 - extents.y_bearing);
    cr->show_text(ranks[y]);
  }

  return true;
}
