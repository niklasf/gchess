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

#include <glibmm/i18n.h>

#include "MainWindow.h"

MainWindow::MainWindow()
{
  set_title(_("GChess"));

  add(m_box);

  m_refActionGroup = Gtk::ActionGroup::create();

  m_refActionGroup->add(Gtk::Action::create("MenuGame", _("Game")));
  m_refActionGroup->add(Gtk::Action::create("Quit", Gtk::Stock::QUIT),
    sigc::mem_fun(*this, &MainWindow::on_action_game_quit));

  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);

  add_accel_group(m_refUIManager->get_accel_group());

  Glib::ustring ui_info =
    "<ui>"
    "  <menubar name='MenuBar'>"
    "    <menu action='MenuGame'>"
    "      <menuitem action='Quit' />"
    "    </menu>"
    "  </menubar>"
    "</ui>";
  m_refUIManager->add_ui_from_string(ui_info);

  Gtk::Widget* menubar = m_refUIManager->get_widget("/MenuBar");
  m_box.pack_start(*menubar, Gtk::PACK_SHRINK);

  m_box.pack_start(m_chessboardWidget);

  show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_action_game_quit()
{
  hide();
}
