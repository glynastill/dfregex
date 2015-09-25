/*-------------------------------------------------------------------------
 * posix regex extensions
 *
 * Copyright (c) 2015, glyn@8kb.co.uk
 * Author: Glyn Astill <glyn@8kb.co.uk>
 *
 *-------------------------------------------------------------------------
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "gnuregex.h"
#include "dfregex.h"

DLLIMPORT int RegexpMatch (const char *str, const char *pattern, const char *flags, int errors)
{
    return regexp_match(str, pattern, flags, errors);
}

DLLIMPORT int RegexpMatches(const char *str, const char *pattern, const char *flags, char *output, int output_len, int errors)
{
    char        *matches = regexp_matches(str, pattern, flags, errors);
    int         matches_len;
    int         result = 0;

    if (matches != NULL)
    {
        matches_len = strlen(matches);
        if (matches_len <= output_len)
        {
            strncpy(output, matches, matches_len);
            result = 0;
        }
        else
            result = -1;

        wfree(matches);
    }
    else
        result = -2;

    return result;
}

DLLIMPORT int RegexpReplace(const char *str, const char *pattern, const char *replacement, const char *flags, char *output, int output_len, int errors)
{
    char        *replaced = regexp_replace(str, pattern, replacement, flags, errors);
    int         replaced_len;
    int         result = 0;

    if (replaced != NULL)
    {
        replaced_len = strlen(replaced);

        if (replaced_len <= output_len)
        {
            strncpy(output, replaced, replaced_len);
            result = 0;
        }
        else
            result = -1;

        wfree(replaced);
    }
    else
        result = -2;


    return result;
}

BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
