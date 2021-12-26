/*
 * Copyright (c) 1997, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_UTILITIES_MACROS_HPP
#define SHARE_VM_UTILITIES_MACROS_HPP

// Use this to mark code that needs to be cleaned up (for development only)
#define NEEDS_CLEANUP

// Makes a string of the argument (which is not macro-expanded)
#define STR(a)  #a

// Makes a string of the macro expansion of a
#define XSTR(a) STR(a)

// -DINCLUDE_<something>=0 | 1 can be specified on the command line to include
// or exclude functionality.

#ifndef INCLUDE_JVMTI
#define INCLUDE_JVMTI 1
#endif  // INCLUDE_JVMTI

#if INCLUDE_JVMTI
#define JVMTI_ONLY(x) x
#define NOT_JVMTI(x)
#define NOT_JVMTI_RETURN
#define NOT_JVMTI_RETURN_(code) /* next token must be ; */
#else
#define JVMTI_ONLY(x)
#define NOT_JVMTI(x) x
#define NOT_JVMTI_RETURN { return; }
#define NOT_JVMTI_RETURN_(code) { return code; }
#endif // INCLUDE_JVMTI

#ifndef INCLUDE_FPROF
#define INCLUDE_FPROF 1
#endif

#if INCLUDE_FPROF
#define NOT_FPROF_RETURN        /* next token must be ; */
#define NOT_FPROF_RETURN_(code) /* next token must be ; */
#else
#define NOT_FPROF_RETURN                {}
#define NOT_FPROF_RETURN_(code) { return code; }
#endif // INCLUDE_FPROF

#ifndef INCLUDE_VM_STRUCTS
#define INCLUDE_VM_STRUCTS 1
#endif

#if INCLUDE_VM_STRUCTS
#define NOT_VM_STRUCTS_RETURN        /* next token must be ; */
#define NOT_VM_STRUCTS_RETURN_(code) /* next token must be ; */
#else
#define NOT_VM_STRUCTS_RETURN           {}
#define NOT_VM_STRUCTS_RETURN_(code) { return code; }
#endif // INCLUDE_VM_STRUCTS

#ifndef INCLUDE_JNI_CHECK
#define INCLUDE_JNI_CHECK 1
#endif

#if INCLUDE_JNI_CHECK
#define NOT_JNI_CHECK_RETURN        /* next token must be ; */
#define NOT_JNI_CHECK_RETURN_(code) /* next token must be ; */
#else
#define NOT_JNI_CHECK_RETURN            {}
#define NOT_JNI_CHECK_RETURN_(code) { return code; }
#endif // INCLUDE_JNI_CHECK

#ifndef INCLUDE_SERVICES
#define INCLUDE_SERVICES 1
#endif

#if INCLUDE_SERVICES
#define NOT_SERVICES_RETURN        /* next token must be ; */
#define NOT_SERVICES_RETURN_(code) /* next token must be ; */
#else
#define NOT_SERVICES_RETURN             {}
#define NOT_SERVICES_RETURN_(code) { return code; }
#endif // INCLUDE_SERVICES

#ifndef INCLUDE_CDS
#define INCLUDE_CDS 1
#endif

#if INCLUDE_CDS
#define CDS_ONLY(x) x
#define NOT_CDS(x)
#define NOT_CDS_RETURN        /* next token must be ; */
#define NOT_CDS_RETURN_(code) /* next token must be ; */
#else
#define CDS_ONLY(x)
#define NOT_CDS(x) x
#define NOT_CDS_RETURN          {}
#define NOT_CDS_RETURN_(code) { return code; }
#endif // INCLUDE_CDS

#ifndef INCLUDE_MANAGEMENT
#define INCLUDE_MANAGEMENT 1
#endif // INCLUDE_MANAGEMENT

#if INCLUDE_MANAGEMENT
#define NOT_MANAGEMENT_RETURN        /* next token must be ; */
#define NOT_MANAGEMENT_RETURN_(code) /* next token must be ; */
#else
#define NOT_MANAGEMENT_RETURN        {}
#define NOT_MANAGEMENT_RETURN_(code) { return code; }
#endif // INCLUDE_MANAGEMENT

/*
 * When INCLUDE_ALL_GCS is false the only garbage collectors
 * included in the JVM are defaultNewGeneration and markCompact.
 *
 * When INCLUDE_ALL_GCS is true all garbage collectors are
 * included in the JVM.
 */
#ifndef INCLUDE_ALL_GCS
#define INCLUDE_ALL_GCS 1
#endif // INCLUDE_ALL_GCS

#if INCLUDE_ALL_GCS
#define NOT_ALL_GCS_RETURN        /* next token must be ; */
#define NOT_ALL_GCS_RETURN_(code) /* next token must be ; */
#else
#define NOT_ALL_GCS_RETURN        {}
#define NOT_ALL_GCS_RETURN_(code) { return code; }
#endif // INCLUDE_ALL_GCS

#ifndef INCLUDE_NMT
#define INCLUDE_NMT 1
#endif // INCLUDE_NMT

#if INCLUDE_NMT
#define NOT_NMT_RETURN        /* next token must be ; */
#define NOT_NMT_RETURN_(code) /* next token must be ; */
#else
#define NOT_NMT_RETURN        {}
#define NOT_NMT_RETURN_(code) { return code; }
#endif // INCLUDE_NMT

#ifndef INCLUDE_JFR
#define INCLUDE_JFR 1
#endif

#if INCLUDE_JFR
#define JFR_ONLY(...) __VA_ARGS__
#else
#define JFR_ONLY(...)
#endif

// COMPILER1 variant
#ifdef COMPILER1
#ifdef COMPILER2
  #define TIERED
#endif
#define COMPILER1_PRESENT(...) __VA_ARGS__
#define NOT_COMPILER1(...)
#else // COMPILER1
#define COMPILER1_PRESENT(...)
#define NOT_COMPILER1(...) __VA_ARGS__
#endif // COMPILER1

// COMPILER2 variant
#ifdef COMPILER2
#define COMPILER2_PRESENT(...) __VA_ARGS__
#define NOT_COMPILER2(...)
#else // COMPILER2
#define COMPILER2_PRESENT(...)
#define NOT_COMPILER2(...) __VA_ARGS__
#endif // COMPILER2

#ifdef TIERED
#define TIERED_ONLY(...) __VA_ARGS__
#define NOT_TIERED(...)
#else
#define TIERED_ONLY(...)
#define NOT_TIERED(...) __VA_ARGS__
#endif // TIERED


// PRODUCT variant
#ifdef PRODUCT
#define PRODUCT_ONLY(...) __VA_ARGS__
#define NOT_PRODUCT(...)
#define NOT_PRODUCT_ARG(arg)
#define PRODUCT_RETURN  {}
#define PRODUCT_RETURN0 { return 0; }
#define PRODUCT_RETURN_(code) { code }
#else // PRODUCT
#define PRODUCT_ONLY(...)
#define NOT_PRODUCT(...) __VA_ARGS__
#define NOT_PRODUCT_ARG(arg) arg,
#define PRODUCT_RETURN  /*next token must be ;*/
#define PRODUCT_RETURN0 /*next token must be ;*/
#define PRODUCT_RETURN_(code)  /*next token must be ;*/
#endif // PRODUCT

#ifdef CHECK_UNHANDLED_OOPS
#define CHECK_UNHANDLED_OOPS_ONLY(...) __VA_ARGS__
#define NOT_CHECK_UNHANDLED_OOPS(...)
#else
#define CHECK_UNHANDLED_OOPS_ONLY(...)
#define NOT_CHECK_UNHANDLED_OOPS(...)  __VA_ARGS__
#endif // CHECK_UNHANDLED_OOPS

#ifdef CC_INTERP
#define CC_INTERP_ONLY(...) __VA_ARGS__
#define NOT_CC_INTERP(...)
#else
#define CC_INTERP_ONLY(...)
#define NOT_CC_INTERP(...) __VA_ARGS__
#endif // CC_INTERP

#ifdef ASSERT
#define DEBUG_ONLY(...) __VA_ARGS__
#define NOT_DEBUG(...)
#define NOT_DEBUG_RETURN  /*next token must be ;*/
// Historical.
#define debug_only(...) __VA_ARGS__
#else // ASSERT
#define DEBUG_ONLY(...)
#define NOT_DEBUG(...) __VA_ARGS__
#define NOT_DEBUG_RETURN {}
#define debug_only(...)
#endif // ASSERT

#ifdef  _LP64
#define LP64_ONLY(...) __VA_ARGS__
#define NOT_LP64(...)
#else  // !_LP64
#define LP64_ONLY(...)
#define NOT_LP64(...) __VA_ARGS__
#endif // _LP64

#ifdef LINUX
#define LINUX_ONLY(...) __VA_ARGS__
#define NOT_LINUX(...)
#else
#define LINUX_ONLY(...)
#define NOT_LINUX(...) __VA_ARGS__
#endif

#ifdef __APPLE__
#define MACOS_ONLY(...) __VA_ARGS__
#define NOT_MACOS(...)
#else
#define MACOS_ONLY(...)
#define NOT_MACOS(...) __VA_ARGS__
#endif

#ifdef AIX
#define AIX_ONLY(...) __VA_ARGS__
#define NOT_AIX(...)
#else
#define AIX_ONLY(...)
#define NOT_AIX(...) __VA_ARGS__
#endif

#ifdef SOLARIS
#define SOLARIS_ONLY(...) __VA_ARGS__
#define NOT_SOLARIS(...)
#else
#define SOLARIS_ONLY(...)
#define NOT_SOLARIS(...) __VA_ARGS__
#endif

#ifdef _WINDOWS
#define WINDOWS_ONLY(...) __VA_ARGS__
#define NOT_WINDOWS(...)
#else
#define WINDOWS_ONLY(...)
#define NOT_WINDOWS(...) __VA_ARGS__
#endif

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
#define BSD_ONLY(...) __VA_ARGS__
#define NOT_BSD(...)
#else
#define BSD_ONLY(...)
#define NOT_BSD(...) __VA_ARGS__
#endif

#ifdef _WIN64
#define WIN64_ONLY(...) __VA_ARGS__
#define NOT_WIN64(...)
#else
#define WIN64_ONLY(...)
#define NOT_WIN64(...) __VA_ARGS__
#endif

#if defined(ZERO)
#define ZERO_ONLY(...) __VA_ARGS__
#define NOT_ZERO(...)
#else
#define ZERO_ONLY(...)
#define NOT_ZERO(...) __VA_ARGS__
#endif

#if defined(SHARK)
#define SHARK_ONLY(...) __VA_ARGS__
#define NOT_SHARK(...)
#else
#define SHARK_ONLY(...)
#define NOT_SHARK(...) __VA_ARGS__
#endif

#if defined(IA32) || defined(AMD64)
#define X86
#define X86_ONLY(...) __VA_ARGS__
#define NOT_X86(...)
#else
#undef X86
#define X86_ONLY(...)
#define NOT_X86(...) __VA_ARGS__
#endif

#ifdef IA32
#define IA32_ONLY(...) __VA_ARGS__
#define NOT_IA32(...)
#else
#define IA32_ONLY(...)
#define NOT_IA32(...) __VA_ARGS__
#endif

// This is a REALLY BIG HACK, but on AIX <sys/systemcfg.h> unconditionally defines IA64.
// At least on AIX 7.1 this is a real problem because 'systemcfg.h' is indirectly included
// by 'pthread.h' and other common system headers.

#if defined(IA64) && !defined(AIX)
#define IA64_ONLY(...) __VA_ARGS__
#define NOT_IA64(...)
#else
#define IA64_ONLY(...)
#define NOT_IA64(...) __VA_ARGS__
#endif

#ifdef AMD64
#define AMD64_ONLY(...) __VA_ARGS__
#define NOT_AMD64(...)
#else
#define AMD64_ONLY(...)
#define NOT_AMD64(...) __VA_ARGS__
#endif

#ifdef AARCH64
#define AARCH64_ONLY(...) __VA_ARGS__
#define NOT_AARCH64(...)
#else
#define AARCH64_ONLY(...)
#define NOT_AARCH64(...) __VA_ARGS__
#endif

#define MACOS_AARCH64_ONLY(...) MACOS_ONLY(AARCH64_ONLY(__VA_ARGS__))

#ifdef SPARC
#define SPARC_ONLY(...) __VA_ARGS__
#define NOT_SPARC(...)
#else
#define SPARC_ONLY(...)
#define NOT_SPARC(...) __VA_ARGS__
#endif

#if defined(PPC32) || defined(PPC64)
#ifndef PPC
#define PPC
#endif
#define PPC_ONLY(...) __VA_ARGS__
#define NOT_PPC(...)
#else
#undef PPC
#define PPC_ONLY(...)
#define NOT_PPC(...) __VA_ARGS__
#endif

#ifdef PPC32
#define PPC32_ONLY(...) __VA_ARGS__
#define NOT_PPC32(...)
#else
#define PPC32_ONLY(...)
#define NOT_PPC32(...) __VA_ARGS__
#endif

#ifdef PPC64
#define PPC64_ONLY(...) __VA_ARGS__
#define NOT_PPC64(...)
#else
#define PPC64_ONLY(...)
#define NOT_PPC64(...) __VA_ARGS__
#endif

#ifdef E500V2
#define E500V2_ONLY(...) __VA_ARGS__
#define NOT_E500V2(...)
#else
#define E500V2_ONLY(...)
#define NOT_E500V2(...) __VA_ARGS__
#endif

#ifdef ARM
#define ARM_ONLY(...) __VA_ARGS__
#define NOT_ARM(...)
#else
#define ARM_ONLY(...)
#define NOT_ARM(...) __VA_ARGS__
#endif

#ifdef ARM32
#define ARM32_ONLY(...) __VA_ARGS__
#define NOT_ARM32(...)
#else
#define ARM32_ONLY(...)
#define NOT_ARM32(...) __VA_ARGS__
#endif

#ifdef AARCH32
#define AARCH32_ONLY(...) __VA_ARGS__
#define NOT_AARCH32(...)
#else
#define AARCH32_ONLY(...)
#define NOT_AARCH32(...) __VA_ARGS__
#endif

#ifdef JAVASE_EMBEDDED
#define EMBEDDED_ONLY(...) __VA_ARGS__
#define NOT_EMBEDDED(...)
#else
#define EMBEDDED_ONLY(...)
#define NOT_EMBEDDED(...) __VA_ARGS__
#endif

#ifdef VM_LITTLE_ENDIAN
#define LITTLE_ENDIAN_ONLY(...) __VA_ARGS__
#define BIG_ENDIAN_ONLY(...)
#else
#define LITTLE_ENDIAN_ONLY(...)
#define BIG_ENDIAN_ONLY(...) __VA_ARGS__
#endif

#define define_pd_global(type, name, value) const type pd_##name = value;

#endif // SHARE_VM_UTILITIES_MACROS_HPP
