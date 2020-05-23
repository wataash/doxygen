/******************************************************************************
 *
 *
 *
 *
 * Copyright (C) 1997-2015 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby
 * granted. No representations are made about the suitability of this software
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "doxygen.h"

#define WUTILS_IMPL
#include "/home/wsh/qc/tesc/libwutils/wutils.cc"

/*! \file
 *  \brief main entry point for doxygen
 *
 *  This file contains main()
 */

/*! Default main. The idea of separating this from the rest of doxygen,
 *  is to make it possible to write your own main, with a different
 *  generateOutput() function for instance.
 */
int main(int argc,char **argv)
{
  // {
  //   // #include <fcntl.h>
  //   // #include <signal.h>
  //   // #include <stdbool.h>
  //   // #include <stdint.h>
  //   // #include <stdio.h>
  //   // #include <unistd.h>
  //   static volatile bool stop = true;
  //   if (stop) {
  //     fprintf(stderr, "SIGSTOP %jd\n", (intmax_t)getpid());
  //     // int fd = open(ttyname(STDERR_FILENO), O_WRONLY);
  //     // // int fd = open("/dev/pts/2", O_WRONLY);
  //     // if (fd != -1) {
  //     //   char buf[100];
  //     //   snprintf(buf, sizeof(buf), "SIGSTOP %jd\n", (intmax_t)getpid());
  //     //   (void)write(fd, buf, strnlen(buf, sizeof(buf))); // - 1?
  //     //   close(fd);
  //     // }
  //
  //     kill(getpid(), SIGSTOP);
  //     stop = false;
  //   }
  // }

  initDoxygen();
  readConfiguration(argc,argv);
  checkConfiguration();
  adjustConfiguration();
  parseInput();
  generateOutput();
  return 0;
}

