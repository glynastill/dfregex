/*-------------------------------------------------------------------------
 * posix regex extensions
 *
 * Copyright (c) 2015, glyn@8kb.co.uk
 * Author: Glyn Astill <glyn@8kb.co.uk>
 *
 *-------------------------------------------------------------------------
 */

#ifndef _DFREGEX_H_
#define _DFREGEX_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */


DLLIMPORT int RegexpMatch(const char *str, const char *pattern, const char *flags, int errors);
DLLIMPORT int RegexpMatches(const char *str, const char *pattern, const char *flags, char *output, int output_len, int errors);
DLLIMPORT int RegexpReplace(const char *str, const char *pattern, const char *replacement, const char *flags, char *output, int output_len, int errors);

#endif /* _DFREGEX_H_ */
