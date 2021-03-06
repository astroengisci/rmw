/*
 * messages_rmw.c
 *
 * This file is part of rmw (https://github.com/andy5995/rmw/wiki)
 *
 *  Copyright (C) 2012-2017  Andy Alt (andy400-dev@yahoo.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include "messages_rmw.h"

/**
 * open_file()
 *
 * called if fopen() returns NULL. Print error message
 */
void
open_err (const char *filename, const char *function_name)
{
    /* TRANSLATORS:  "opening" refers to a file  */
    printf (_("  :Error: while opening %s\n"), filename);

    static char combined_msg[MAX_MSG_SIZE];
     /* TRANSLATORS:  "function" refers to a C function  */
    sprintf (combined_msg, _("function: <%s>"), function_name);
    perror (combined_msg);

    return;
}

/**
 * close_file()
 *
 * Closes a file, checks for an error. If error print message and
 * return 1, else, returns 0
 */
short close_file (FILE *file_ptr, const char *filename, const char *function_name)
{
  if (fclose (file_ptr) != EOF)
    return 0;
  else
  {
    /* TRANSLATORS:  "closing" refers to a file  */
    printf (_("  :Error: while closing %s\n"), filename);

    static char combined_msg[MAX_MSG_SIZE];
    sprintf (combined_msg, _("function: <%s>"), function_name);
    perror (combined_msg);

    return ERR_CLOSE;
  }
}

void display_dot_trashinfo_error (const char *dti)
{
  /* TRANSLATORS:  ".trashinfo" should remain untranslated
   *
   *               "format" refers to the layout of the file
   *                contents
   */
  printf (_("  :Error: format of .trashinfo `file %s` is incorrect"), dti);
  printf ("\n");
  return;
}

void msg_warn_restore (int result)
{
  if (result == 0)
    return;

  if (result != FILE_NOT_FOUND)
    /* TRANSLATORS: ignore "Restore()" */
    printf (_(" :warning: Restore() returned %d\n"), result);

  return;
}

void chk_malloc (void *state, const const char *func, const int line)
{
  if (state == NULL)
  {
    printf (_("  :Error: allocating memory\n"));
    exit (EXIT_MALLOC_ERR);
  }
  return;
}
