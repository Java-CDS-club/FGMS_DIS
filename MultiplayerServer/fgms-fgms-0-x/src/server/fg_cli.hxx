/**
 * @file fg_cli.hxx
 * @author Oliver Schroeder
 */
//                                                                              
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, U$
//
// Copyright (C) 2013  Oliver Schroeder
//

/**
 * @class FG_CLI 
 * @brief cisco like command line interface
 * 
 */

//////////////////////////////////////////////////////////////////////
//
//      cisco like command line interface (cli)
//
//////////////////////////////////////////////////////////////////////

#ifndef FG_CLI_HEADER
#define FG_CLI_HEADER

#include <fg_server.hxx>
#include <libcli.hxx>

using namespace LIBCLI;
using namespace std;

class FG_CLI : public CLI
{
public:
	FG_CLI ( FG_SERVER*  fgms, int fd);
private:
	void setup ();
	//////////////////////////////////////////////////
	// general  commands
	//////////////////////////////////////////////////
	int cmd_show_stats	( UNUSED(char *command), UNUSED(char *argv[]), UNUSED(int argc) );
	int cmd_show_version	( UNUSED(char *command), UNUSED(char *argv[]), UNUSED(int argc) );
	int cmd_show_uptime	( UNUSED(char *command), UNUSED(char *argv[]), UNUSED(int argc) );
	int cmd_fgms_die	( UNUSED(char *command), UNUSED(char *argv[]), UNUSED(int argc) );
	//////////////////////////////////////////////////
	// show list of players
	//////////////////////////////////////////////////
	int cmd_user_show   (  char *command, char *argv[], int argc );
private:
	FG_SERVER* fgms;
	int cmd_NOT_IMPLEMENTED (  char *command, char *argv[], int argc );
	//////////////////////////////////////////////////
	//  utility functions
	//////////////////////////////////////////////////
	bool need_help (char* argv);
};

#endif

