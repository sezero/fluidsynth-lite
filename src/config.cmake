#ifndef CONFIG_H
#define CONFIG_H

/* Define if D-Bus support is enabled */
#cmakedefine DBUS_SUPPORT  @DBUS_SUPPORT@

/* Soundfont to load automatically in some use cases */
#cmakedefine DEFAULT_SOUNDFONT "@DEFAULT_SOUNDFONT@"

/* Define to enable FPE checks */
#cmakedefine FPE_CHECK @FPE_CHECK@

/* Define to 1 if you have the <arpa/inet.h> header file. */
#cmakedefine HAVE_ARPA_INET_H @HAVE_ARPA_INET_H@

/* Define to 1 if you have clock_gettime(). */
#cmakedefine HAVE_CLOCK_GETTIME @HAVE_CLOCK_GETTIME@

/* Define if you have <alloca.h> file. */
#cmakedefine HAVE_ALLOCA_H @HAVE_ALLOCA_H@

/* Define to 1 if you have the <errno.h> header file. */
#cmakedefine HAVE_ERRNO_H @HAVE_ERRNO_H@

/* Define to 1 if you have the <fcntl.h> header file. */
#cmakedefine HAVE_FCNTL_H @HAVE_FCNTL_H@

/* Define to 1 if you have the <inttypes.h> header file. */
#cmakedefine HAVE_INTTYPES_H @HAVE_INTTYPES_H@

/* Define to 1 if you have the `pthread' library (-lpthread). */
#cmakedefine HAVE_LIBPTHREAD @HAVE_LIBPTHREAD@

/* Define to 1 if you have the <limits.h> header file. */
#cmakedefine HAVE_LIMITS_H @HAVE_LIMITS_H@

/* Define to 1 if you have the <machine/soundcard.h> header file. */
#cmakedefine HAVE_MACHINE_SOUNDCARD_H @HAVE_MACHINE_SOUNDCARD_H@

/* Define to 1 if you have the <math.h> header file. */
#cmakedefine HAVE_MATH_H @HAVE_MATH_H@

/* Define to 1 if you have the <memory.h> header file. */
#cmakedefine HAVE_MEMORY_H @HAVE_MEMORY_H@

/* Define to 1 if you have the <pthread.h> header file. */
#cmakedefine HAVE_PTHREAD_H @HAVE_PTHREAD_H@

/* Define to 1 if you have the <signal.h> header file. */
#cmakedefine HAVE_SIGNAL_H @HAVE_SIGNAL_H@

/* Define to 1 if you have the <stdarg.h> header file. */
#cmakedefine HAVE_STDARG_H @HAVE_STDARG_H@

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H @HAVE_STDINT_H@

/* Define to 1 if you have the <stdbool.h> header file. */
#cmakedefine HAVE_STDBOOL_H @HAVE_STDBOOL_H@

/* Define to 1 if you have the <stdatomic.h> header file. */
#cmakedefine HAVE_STDATOMIC_H @HAVE_STDATOMIC_H@

/* Define to 1 if you have the <stdio.h> header file. */
#cmakedefine HAVE_STDIO_H @HAVE_STDIO_H@

/* Define to 1 if you have the <stdlib.h> header file. */
#cmakedefine HAVE_STDLIB_H @HAVE_STDLIB_H@

/* Define to 1 if you have the <strings.h> header file. */
#cmakedefine HAVE_STRINGS_H @HAVE_STRINGS_H@

/* Define to 1 if you have the <threads.h> header file. */
#cmakedefine HAVE_THREADS_H @HAVE_THREADS_H@

/* Define to 1 if you have the <string.h> header file. */
#cmakedefine HAVE_STRING_H @HAVE_STRING_H@

/* Define to 1 if you have the <sys/stat.h> header file. */
#cmakedefine HAVE_SYS_STAT_H @HAVE_SYS_STAT_H@

/* Define to 1 if you have the <sys/time.h> header file. */
#cmakedefine HAVE_SYS_TIME_H @HAVE_SYS_TIME_H@

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H @HAVE_SYS_TYPES_H@

/* Define to 1 if you have the <io.h> header file. */
#cmakedefine HAVE_IO_H @HAVE_IO_H@

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H @HAVE_UNISTD_H@

/* Define to 1 if you have the <windows.h> header file. */
#cmakedefine HAVE_WINDOWS_H @HAVE_WINDOWS_H@

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
#cmakedefine NO_MINUS_C_MINUS_O @NO_MINUS_C_MINUS_O@

/* Name of package */
#cmakedefine PACKAGE "@PACKAGE@"

/* Define to 1 if you have the ANSI C header files. */
#cmakedefine STDC_HEADERS @STDC_HEADERS@

/* Define to enable SIGFPE assertions */
#cmakedefine TRAP_ON_FPE @TRAP_ON_FPE@

/* Version number of package */
#cmakedefine VERSION @FLUIDSYNTH_VERSION@

/* Define to do all DSP in single floating point precision */
#cmakedefine WITH_FLOAT @WITH_FLOAT@

/* Define to profile the DSP code */
#cmakedefine WITH_PROFILING @WITH_PROFILING@

/* Define if the compiler supports VLA */ 
#cmakedefine SUPPORTS_VLA @SUPPORTS_VLA@ 

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
#cmakedefine WORDS_BIGENDIAN @WORDS_BIGENDIAN@

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#cmakedefine inline @INLINE_KEYWORD@
#endif

#endif /* CONFIG_H */
