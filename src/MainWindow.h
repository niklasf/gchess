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

#ifndef GCHESS_MAINWINDOW_H
#define GCHESS_MAINWINDOW_H

#include <gtkmm.h>

#include "ChessboardWidget.h"

class MainWindow : public Gtk::Window {
  public:
    MainWindow();
    virtual ~MainWindow();

  protected:
    Gtk::VBox m_box;
    ChessboardWidget m_chessboardWidget;

    Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
    Glib::RefPtr<Gtk::UIManager> m_refUIManager;

    void on_action_game_quit();
};

#endif
