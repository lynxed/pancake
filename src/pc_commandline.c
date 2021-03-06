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

#include "pc_commandline.h"

const gchar* pc_program_invocation_name;

static PcCommandlineOpts pc_commandline_opts =
{
	.config_path = NULL,
	.module_path = NULL
};

/* possible commandline options */
static GOptionEntry cmdline_opts[] =
{
	{ "config", 'c', 0, G_OPTION_ARG_FILENAME, &pc_commandline_opts.config_path,
			"Path to configfile to use", "PATH" },
	{ "modulepath", 'm', 0, G_OPTION_ARG_FILENAME,
			&pc_commandline_opts.module_path, "Path to modules", "PATH" },
	{ "modulehelp", 'd', 0, G_OPTION_ARG_NONE,
			&pc_commandline_opts.module_help,
                            "Prints a description of all modules and their\n"
"                            configuration-options in search-path to stdout.\n"
"                            The output will be a valid configurationfile and\n"
"                            can be used as template for such one." },
	{ NULL }
};

const PcCommandlineOpts* pc_commandline_parse(int* argc, char*** argv)
{
	gboolean err = FALSE;
	GError* error = NULL;
	GOptionContext* opt_context;
	opt_context = g_option_context_new(NULL);
	g_option_context_set_summary(opt_context, "A highly modular panel for X");
	g_option_context_add_main_entries(opt_context, cmdline_opts, NULL);
	GOptionGroup* default_group = gtk_get_option_group(TRUE);
	g_option_context_add_group(opt_context, default_group);
	if(!g_option_context_parse(opt_context, argc, argv, &error))
	{
		g_critical("failed to parse arguments: %s", error->message);
		g_error_free(error);
		err = TRUE;
	}

	if(!err && *argc != 1)
	{
		g_critical("failed to parse arguments: Unknown argument %s",
				(*argv)[1]);
		err = TRUE;
	}
	
	g_option_context_free(opt_context);

	return (err ? NULL : &pc_commandline_opts);
}

