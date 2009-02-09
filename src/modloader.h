/**
 * Copyright (C) 2009 Simon Schönfeld <simon.schoenfeld@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef MODLOADER_H
#define MODLOADER_H

#include <gtk/gtk.h>
#include "commandline.h"
#include "module.h"

/**
 * @brief Initialises the module-loader
 *
 * @param cmdline_opts The options parse from commandline
 * @return TRUE on success, FALSE otherwise
 **/
gboolean pc_modloader_init(const PcCommandlineOpts* cmdline_opts);

/**
 * @brief Loads a module
 *
 * @param name the name of the module to load
 * @return the newly loaded module, or NULL if an error occured
 **/
PancakeModule* pc_modloader_load(PancakeModuleType type, const gchar* name);

/**
 * @brief Cleans up the module-subsystem
 **/
void pc_modloader_cleanup();

#endif

