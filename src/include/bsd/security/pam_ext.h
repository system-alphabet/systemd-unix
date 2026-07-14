#pragma once

/* Linux-PAM specific extension functions.
 * On FreeBSD with OpenPAM, these are not available. Provide stubs/declarations
 * so that systemd code that dynamically loads libpam can compile. */

#include <stdarg.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

/* Declare the Linux-PAM extension functions so that DLSYM_PROTOTYPE can take their typeof().
 * The actual implementations are loaded via dlopen() at runtime. */
int pam_syslog(const pam_handle_t *pamh, int priority, const char *fmt, ...);
int pam_vsyslog(const pam_handle_t *pamh, int priority, const char *fmt, va_list args);
int pam_get_authtok_noverify(pam_handle_t *pamh, const char **authtok);
int pam_get_authtok_verify(pam_handle_t *pamh, const char **authtok);

/* pam_info() macro from Linux-PAM: expands to pam_prompt(PAM_TEXT_INFO, ...) */
