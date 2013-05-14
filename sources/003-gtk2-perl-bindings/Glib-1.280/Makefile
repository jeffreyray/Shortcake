# This Makefile is for the Glib extension to perl.
#
# It was generated automatically by MakeMaker version
# 6.6302 (Revision: 66302) from the contents of
# Makefile.PL. Don't edit this file, edit Makefile.PL instead.
#
#       ANY CHANGES MADE HERE WILL BE LOST!
#
#   MakeMaker ARGV: ()
#

#   MakeMaker Parameters:

#     ABSTRACT_FROM => q[lib/Glib.pm]
#     BUILD_REQUIRES => {  }
#     CONFIGURE_REQUIRES => {  }
#     DL_FUNCS => { Glib=>[] }
#     FUNCLIST => [q[SvGChar], q[SvGKeyFile], q[SvGParamFlags], q[SvGParamSpec], q[SvGSignalFlags], q[SvGInt64], q[SvGUInt64], q[_gperl_attach_mg], q[_gperl_call_XS], q[_gperl_find_mg], q[_gperl_remove_mg], q[gperl_alloc_temp], q[gperl_argv_free], q[gperl_argv_new], q[gperl_argv_update], q[gperl_boxed_package_from_type], q[gperl_boxed_type_from_package], q[gperl_callback_destroy], q[gperl_callback_invoke], q[gperl_callback_new], q[gperl_closure_new], q[gperl_closure_new_with_marshaller], q[gperl_convert_back_enum], q[gperl_convert_back_enum_pass_unknown], q[gperl_convert_back_flags], q[gperl_convert_enum], q[gperl_convert_flag_one], q[gperl_convert_flags], q[gperl_croak_gerror], q[gperl_default_boxed_wrapper_class], q[gperl_filename_from_sv], q[gperl_format_variable_for_output], q[gperl_fundamental_package_from_type], q[gperl_fundamental_type_from_package], q[gperl_gerror_from_sv], q[gperl_get_boxed_check], q[gperl_get_object], q[gperl_get_object_check], q[gperl_handle_logs_for], q[gperl_hv_take_sv], q[gperl_install_exception_handler], q[gperl_new_boxed], q[gperl_new_boxed_copy], q[gperl_new_object], q[gperl_object_check_type], q[gperl_object_package_from_type], q[gperl_object_set_no_warn_unreg_subclass], q[gperl_object_stash_from_type], q[gperl_object_type_from_package], q[gperl_option_context_get_type], q[gperl_option_group_get_type], q[gperl_package_from_type], q[gperl_param_spec_package_from_type], q[gperl_param_spec_type_from_package], q[gperl_prepend_isa], q[gperl_register_boxed], q[gperl_register_boxed_alias], q[gperl_register_boxed_synonym], q[gperl_register_error_domain], q[gperl_register_fundamental], q[gperl_register_fundamental_alias], q[gperl_register_object], q[gperl_register_object_alias], q[gperl_register_param_spec], q[gperl_register_sink_func], q[gperl_remove_exception_handler], q[gperl_run_exception_handlers], q[gperl_set_isa], q[gperl_signal_connect], q[gperl_signal_set_marshaller_for], q[gperl_str_eq], q[gperl_str_hash], q[gperl_sv_copy], q[gperl_sv_is_defined], q[gperl_sv_free], q[gperl_sv_from_filename], q[gperl_sv_from_gerror], q[gperl_sv_from_value], q[gperl_sv_get_type], q[gperl_try_convert_enum], q[gperl_try_convert_flag], q[gperl_type_class], q[gperl_type_from_package], q[gperl_value_from_sv], q[newSVGChar], q[newSVGParamFlags], q[newSVGParamSpec], q[newSVGSignalFlags], q[newSVGSignalInvocationHint], q[newSVGSignalQuery], q[newSVGInt64], q[newSVGUInt64]]
#     INC => q[-I. -mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include]
#     LIBS => q[-LC:/devel/Shortcake/sandbox/perl/lib -lgobject-2.0 -lgthread-2.0 -lglib-2.0 -lintl]
#     MAN3PODS => { $(INST_LIB)\Glib\Boxed.pod=>q[$(INST_MAN3DIR)/Glib::Boxed.$(MAN3EXT)], $(INST_LIB)\Glib\Signal.pod=>q[$(INST_MAN3DIR)/Glib::Signal.$(MAN3EXT)], $(INST_LIB)\Glib\Param\Int.pod=>q[$(INST_MAN3DIR)/Glib::Param::Int.$(MAN3EXT)], $(INST_LIB)\Glib\Log.pod=>q[$(INST_MAN3DIR)/Glib::Log.$(MAN3EXT)], $(INST_LIB)/$(FULLEXT)/xsapi.pod=>q[$(INST_MAN3DIR)/Glib::xsapi.$(MAN3EXT)], lib/Glib/Object/Subclass.pm=>q[$(INST_MAN3DIR)/Glib::Object::Subclass.$(MAN3EXT)], $(INST_LIB)\Glib\Param\UInt.pod=>q[$(INST_MAN3DIR)/Glib::Param::UInt.$(MAN3EXT)], $(INST_LIB)\Glib\Param\GType.pod=>q[$(INST_MAN3DIR)/Glib::Param::GType.$(MAN3EXT)], $(INST_LIB)\Glib\Param\UInt64.pod=>q[$(INST_MAN3DIR)/Glib::Param::UInt64.$(MAN3EXT)], $(INST_LIB)\Glib\Object.pod=>q[$(INST_MAN3DIR)/Glib::Object.$(MAN3EXT)], $(INST_LIB)\Glib\Utils.pod=>q[$(INST_MAN3DIR)/Glib::Utils.$(MAN3EXT)], $(INST_LIB)\Glib\Flags.pod=>q[$(INST_MAN3DIR)/Glib::Flags.$(MAN3EXT)], $(INST_LIB)\Glib\BookmarkFile.pod=>q[$(INST_MAN3DIR)/Glib::BookmarkFile.$(MAN3EXT)], $(INST_LIB)\Glib\version.pod=>q[$(INST_MAN3DIR)/Glib::version.$(MAN3EXT)], $(INST_LIB)\Glib\Param\Flags.pod=>q[$(INST_MAN3DIR)/Glib::Param::Flags.$(MAN3EXT)], $(INST_LIB)/$(FULLEXT)/index.pod=>q[$(INST_MAN3DIR)/$(NAME)::index.$(MAN3EXT)], $(INST_LIB)\Glib\ParamSpec.pod=>q[$(INST_MAN3DIR)/Glib::ParamSpec.$(MAN3EXT)], $(INST_LIB)\Glib\Type.pod=>q[$(INST_MAN3DIR)/Glib::Type.$(MAN3EXT)], $(INST_LIB)\Glib\Error.pod=>q[$(INST_MAN3DIR)/Glib::Error.$(MAN3EXT)], $(INST_LIB)\Glib\Param\Int64.pod=>q[$(INST_MAN3DIR)/Glib::Param::Int64.$(MAN3EXT)], $(INST_LIB)\Glib\MainLoop.pod=>q[$(INST_MAN3DIR)/Glib::MainLoop.$(MAN3EXT)], lib/Glib/GenPod.pm=>q[$(INST_MAN3DIR)/Glib::GenPod.$(MAN3EXT)], $(INST_LIB)\Glib\KeyFile.pod=>q[$(INST_MAN3DIR)/Glib::KeyFile.$(MAN3EXT)], $(INST_LIB)\Glib\OptionGroup.pod=>q[$(INST_MAN3DIR)/Glib::OptionGroup.$(MAN3EXT)], lib/Glib.pm=>q[$(INST_MAN3DIR)/Glib.$(MAN3EXT)], $(INST_LIB)\Glib\Param\Double.pod=>q[$(INST_MAN3DIR)/Glib::Param::Double.$(MAN3EXT)], $(INST_LIB)\Glib\Param\Enum.pod=>q[$(INST_MAN3DIR)/Glib::Param::Enum.$(MAN3EXT)], $(INST_LIB)\Glib\OptionContext.pod=>q[$(INST_MAN3DIR)/Glib::OptionContext.$(MAN3EXT)], devel.pod=>q[$(INST_MAN3DIR)/Glib::devel.$(MAN3EXT)], lib/Glib/MakeHelper.pm=>q[$(INST_MAN3DIR)/Glib::MakeHelper.$(MAN3EXT)], lib/Glib/ParseXSDoc.pm=>q[$(INST_MAN3DIR)/Glib::ParseXSDoc.$(MAN3EXT)], lib/Glib/CodeGen.pm=>q[$(INST_MAN3DIR)/Glib::CodeGen.$(MAN3EXT)], $(INST_LIB)\Glib\Markup.pod=>q[$(INST_MAN3DIR)/Glib::Markup.$(MAN3EXT)] }
#     META_MERGE => { no_index=>{ file=>[q[Glib.xs], q[GError.xs], q[GUtils.xs], q[GLog.xs], q[GType.xs], q[GBoxed.xs], q[GObject.xs], q[GValue.xs], q[GClosure.xs], q[GSignal.xs], q[GMainLoop.xs], q[GIOChannel.xs], q[GParamSpec.xs], q[GKeyFile.xs], q[GOption.xs], q[GBookmarkFile.xs], q[Makefile.PL], q[xsapi.pod.head], q[xsapi.pod.foot]], package=>q[MY] }, prereqs=>{ configure=>{ requires=>{ ExtUtils::Depends=>q[0.300], ExtUtils::PkgConfig=>q[1.000] } } }, resources=>{ repository=>{ web=>q[http://git.gnome.org/browse/perl-Glib], url=>q[git://git.gnome.org/perl-Glib], type=>q[git] }, x_MailingList=>q[https://mail.gnome.org/mailman/listinfo/gtk-perl-list], homepage=>q[http://gtk2-perl.sourceforge.net], bugtracker=>{ web=>q[http://rt.cpan.org/Public/Dist/Display.html?Name=Glib], mailto=>q[bug-Glib [at] rt.cpan.org] }, license=>q[http://www.gnu.org/licenses/lgpl-2.1.html] }, meta-spec=>{ version=>q[2], url=>q[http://search.cpan.org/perldoc?CPAN::Meta::Spec] }, author=>[q[gtk2-perl Team <gtk-perl-list at gnome dot org>]], license=>q[lgpl_2_1], release_status=>q[stable] }
#     NAME => q[Glib]
#     OBJECT => q[Glib$(OBJ_EXT) GError$(OBJ_EXT) GUtils$(OBJ_EXT) GLog$(OBJ_EXT) GType$(OBJ_EXT) GBoxed$(OBJ_EXT) GObject$(OBJ_EXT) GValue$(OBJ_EXT) GClosure$(OBJ_EXT) GSignal$(OBJ_EXT) GMainLoop$(OBJ_EXT) GIOChannel$(OBJ_EXT) GParamSpec$(OBJ_EXT) GKeyFile$(OBJ_EXT) GOption$(OBJ_EXT) GBookmarkFile$(OBJ_EXT) gperl-gtypes$(OBJ_EXT)]
#     PM => { build/IFiles.pm=>q[$(INST_ARCHLIB)/$(FULLEXT)/Install/Files.pm], lib/Glib/GenPod.pm=>q[$(INST_LIBDIR)/Glib/GenPod.pm], lib/Glib.pm=>q[$(INST_LIBDIR)/Glib.pm], gperl.h=>q[$(INST_ARCHLIB)/$(FULLEXT)/Install/gperl.h], lib/Glib/Object/Subclass.pm=>q[$(INST_LIBDIR)/Glib/Object/Subclass.pm], devel.pod=>q[$(INST_LIBDIR)/Glib/devel.pod], gperl_marshal.h=>q[$(INST_ARCHLIB)/$(FULLEXT)/Install/gperl_marshal.h], lib/Glib/ParseXSDoc.pm=>q[$(INST_LIBDIR)/Glib/ParseXSDoc.pm], lib/Glib/MakeHelper.pm=>q[$(INST_LIBDIR)/Glib/MakeHelper.pm], lib/Glib/CodeGen.pm=>q[$(INST_LIBDIR)/Glib/CodeGen.pm], doctypes=>q[$(INST_ARCHLIB)/$(FULLEXT)/Install/doctypes], C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap=>q[$(INST_ARCHLIB)/$(FULLEXT)/Install/typemap] }
#     PREREQ_PM => { ExtUtils::Depends=>q[0.300], ExtUtils::PkgConfig=>q[1.000] }
#     TYPEMAPS => [q[C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap]]
#     VERSION_FROM => q[lib/Glib.pm]
#     XS => { GIOChannel.xs=>q[GIOChannel.c], GKeyFile.xs=>q[GKeyFile.c], GUtils.xs=>q[GUtils.c], GError.xs=>q[GError.c], GBoxed.xs=>q[GBoxed.c], GObject.xs=>q[GObject.c], GMainLoop.xs=>q[GMainLoop.c], GValue.xs=>q[GValue.c], Glib.xs=>q[Glib.c], GOption.xs=>q[GOption.c], GSignal.xs=>q[GSignal.c], GType.xs=>q[GType.c], GLog.xs=>q[GLog.c], GClosure.xs=>q[GClosure.c], GBookmarkFile.xs=>q[GBookmarkFile.c], GParamSpec.xs=>q[GParamSpec.c] }
#     XSPROTOARG => q[-noprototypes]
#     clean => { FILES=>q[Glib$(OBJ_EXT) GError$(OBJ_EXT) GUtils$(OBJ_EXT) GLog$(OBJ_EXT) GType$(OBJ_EXT) GBoxed$(OBJ_EXT) GObject$(OBJ_EXT) GValue$(OBJ_EXT) GClosure$(OBJ_EXT) GSignal$(OBJ_EXT) GMainLoop$(OBJ_EXT) GIOChannel$(OBJ_EXT) GParamSpec$(OBJ_EXT) GKeyFile$(OBJ_EXT) GOption$(OBJ_EXT) GBookmarkFile$(OBJ_EXT) gperl-gtypes$(OBJ_EXT)] }
#     macro => { INST_DYNAMIC_LIB=>q[$(INST_ARCHAUTODIR)/$(BASEEXT)$(LIB_EXT)] }

# --- MakeMaker post_initialize section:


# --- MakeMaker const_config section:

# These definitions are from config.sh (via C:/devel/Shortcake/sandbox/perl/lib/Config.pm).
# They may have been overridden via Makefile.PL or on the command line.
AR = ar
CC = gcc
CCCDLFLAGS =  
CCDLFLAGS =  
DLEXT = dll
DLSRC = dl_win32.xs
EXE_EXT = .exe
FULL_AR = 
LD = g++
LDDLFLAGS = -mdll -s -L"C:\devel\Shortcake\sandbox\perl\lib\CORE" -L"C:\devel\Shortcake\sandbox\c\lib"
LDFLAGS = -s -L"C:\devel\Shortcake\sandbox\perl\lib\CORE" -L"C:\devel\Shortcake\sandbox\c\lib"
LIBC = 
LIB_EXT = .a
OBJ_EXT = .o
OSNAME = MSWin32
OSVERS = 4.0
RANLIB = rem
SITELIBEXP = C:\devel\Shortcake\sandbox\perl\site\lib
SITEARCHEXP = C:\devel\Shortcake\sandbox\perl\site\lib
SO = dll
VENDORARCHEXP = C:\devel\Shortcake\sandbox\perl\vendor\lib
VENDORLIBEXP = C:\devel\Shortcake\sandbox\perl\vendor\lib


# --- MakeMaker constants section:

# Get dmake to read long commands like PM_TO_BLIB
MAXLINELENGTH = 65536

AR_STATIC_ARGS = cr
DIRFILESEP = \\
DFSEP = $(DIRFILESEP)
NAME = Glib
NAME_SYM = Glib
VERSION = 1.280
VERSION_MACRO = VERSION
VERSION_SYM = 1_280
DEFINE_VERSION = -D$(VERSION_MACRO)=\"$(VERSION)\"
XS_VERSION = 1.280
XS_VERSION_MACRO = XS_VERSION
XS_DEFINE_VERSION = -D$(XS_VERSION_MACRO)=\"$(XS_VERSION)\"
INST_ARCHLIB = blib\arch
INST_SCRIPT = blib\script
INST_BIN = blib\bin
INST_LIB = blib\lib
INST_MAN1DIR = blib\man1
INST_MAN3DIR = blib\man3
MAN1EXT = 1
MAN3EXT = 3
INSTALLDIRS = site
DESTDIR = 
PREFIX = $(SITEPREFIX)
PERLPREFIX = C:\devel\Shortcake\sandbox\perl
SITEPREFIX = C:\devel\Shortcake\sandbox\perl\site
VENDORPREFIX = C:\devel\Shortcake\sandbox\perl\vendor
INSTALLPRIVLIB = C:\devel\Shortcake\sandbox\perl\lib
DESTINSTALLPRIVLIB = $(DESTDIR)$(INSTALLPRIVLIB)
INSTALLSITELIB = C:\devel\Shortcake\sandbox\perl\site\lib
DESTINSTALLSITELIB = $(DESTDIR)$(INSTALLSITELIB)
INSTALLVENDORLIB = C:\devel\Shortcake\sandbox\perl\vendor\lib
DESTINSTALLVENDORLIB = $(DESTDIR)$(INSTALLVENDORLIB)
INSTALLARCHLIB = C:\devel\Shortcake\sandbox\perl\lib
DESTINSTALLARCHLIB = $(DESTDIR)$(INSTALLARCHLIB)
INSTALLSITEARCH = C:\devel\Shortcake\sandbox\perl\site\lib
DESTINSTALLSITEARCH = $(DESTDIR)$(INSTALLSITEARCH)
INSTALLVENDORARCH = C:\devel\Shortcake\sandbox\perl\vendor\lib
DESTINSTALLVENDORARCH = $(DESTDIR)$(INSTALLVENDORARCH)
INSTALLBIN = C:\devel\Shortcake\sandbox\perl\bin
DESTINSTALLBIN = $(DESTDIR)$(INSTALLBIN)
INSTALLSITEBIN = C:\devel\Shortcake\sandbox\perl\site\bin
DESTINSTALLSITEBIN = $(DESTDIR)$(INSTALLSITEBIN)
INSTALLVENDORBIN = C:\devel\Shortcake\sandbox\perl\bin
DESTINSTALLVENDORBIN = $(DESTDIR)$(INSTALLVENDORBIN)
INSTALLSCRIPT = C:\devel\Shortcake\sandbox\perl\bin
DESTINSTALLSCRIPT = $(DESTDIR)$(INSTALLSCRIPT)
INSTALLSITESCRIPT = C:\devel\Shortcake\sandbox\perl\site\bin
DESTINSTALLSITESCRIPT = $(DESTDIR)$(INSTALLSITESCRIPT)
INSTALLVENDORSCRIPT = C:\devel\Shortcake\sandbox\perl\bin
DESTINSTALLVENDORSCRIPT = $(DESTDIR)$(INSTALLVENDORSCRIPT)
INSTALLMAN1DIR = none
DESTINSTALLMAN1DIR = $(DESTDIR)$(INSTALLMAN1DIR)
INSTALLSITEMAN1DIR = $(INSTALLMAN1DIR)
DESTINSTALLSITEMAN1DIR = $(DESTDIR)$(INSTALLSITEMAN1DIR)
INSTALLVENDORMAN1DIR = $(INSTALLMAN1DIR)
DESTINSTALLVENDORMAN1DIR = $(DESTDIR)$(INSTALLVENDORMAN1DIR)
INSTALLMAN3DIR = none
DESTINSTALLMAN3DIR = $(DESTDIR)$(INSTALLMAN3DIR)
INSTALLSITEMAN3DIR = $(INSTALLMAN3DIR)
DESTINSTALLSITEMAN3DIR = $(DESTDIR)$(INSTALLSITEMAN3DIR)
INSTALLVENDORMAN3DIR = $(INSTALLMAN3DIR)
DESTINSTALLVENDORMAN3DIR = $(DESTDIR)$(INSTALLVENDORMAN3DIR)
PERL_LIB = C:\devel\Shortcake\sandbox\perl\lib
PERL_ARCHLIB = C:\devel\Shortcake\sandbox\perl\lib
LIBPERL_A = libperl.a
FIRST_MAKEFILE = Makefile
MAKEFILE_OLD = Makefile.old
MAKE_APERL_FILE = Makefile.aperl
PERLMAINCC = $(CC)
PERL_INC = C:\devel\Shortcake\sandbox\perl\lib\CORE
PERL = C:\devel\Shortcake\sandbox\perl\bin\perl.exe
FULLPERL = C:\devel\Shortcake\sandbox\perl\bin\perl.exe
ABSPERL = $(PERL)
PERLRUN = $(PERL)
FULLPERLRUN = $(FULLPERL)
ABSPERLRUN = $(ABSPERL)
PERLRUNINST = $(PERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"
FULLPERLRUNINST = $(FULLPERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"
ABSPERLRUNINST = $(ABSPERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"
PERL_CORE = 0
PERM_DIR = 755
PERM_RW = 644
PERM_RWX = 755

MAKEMAKER   = C:/devel/Shortcake/sandbox/perl/lib/ExtUtils/MakeMaker.pm
MM_VERSION  = 6.6302
MM_REVISION = 66302

# FULLEXT = Pathname for extension directory (eg Foo/Bar/Oracle).
# BASEEXT = Basename part of FULLEXT. May be just equal FULLEXT. (eg Oracle)
# PARENT_NAME = NAME without BASEEXT and no trailing :: (eg Foo::Bar)
# DLBASE  = Basename part of dynamic library. May be just equal BASEEXT.
MAKE = dmake
FULLEXT = Glib
BASEEXT = Glib
PARENT_NAME = 
DLBASE = $(BASEEXT)
VERSION_FROM = lib/Glib.pm
INC = -I. -mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include
OBJECT = Glib$(OBJ_EXT) GError$(OBJ_EXT) GUtils$(OBJ_EXT) GLog$(OBJ_EXT) GType$(OBJ_EXT) GBoxed$(OBJ_EXT) GObject$(OBJ_EXT) GValue$(OBJ_EXT) GClosure$(OBJ_EXT) GSignal$(OBJ_EXT) GMainLoop$(OBJ_EXT) GIOChannel$(OBJ_EXT) GParamSpec$(OBJ_EXT) GKeyFile$(OBJ_EXT) GOption$(OBJ_EXT) GBookmarkFile$(OBJ_EXT) gperl-gtypes$(OBJ_EXT)
LDFROM = $(OBJECT)
LINKTYPE = dynamic
BOOTDEP = 

# Handy lists of source code files:
XS_FILES = GBookmarkFile.xs \
	GBoxed.xs \
	GClosure.xs \
	GError.xs \
	GIOChannel.xs \
	GKeyFile.xs \
	GLog.xs \
	GMainLoop.xs \
	GObject.xs \
	GOption.xs \
	GParamSpec.xs \
	GSignal.xs \
	GType.xs \
	GUtils.xs \
	GValue.xs \
	Glib.xs
C_FILES  = GBookmarkFile.c \
	GBoxed.c \
	GClosure.c \
	GError.c \
	GIOChannel.c \
	GKeyFile.c \
	GLog.c \
	GMainLoop.c \
	GObject.c \
	GOption.c \
	GParamSpec.c \
	GSignal.c \
	GType.c \
	GUtils.c \
	GValue.c \
	Glib.c \
	gperl-gtypes.c
O_FILES  = GBookmarkFile.o \
	GBoxed.o \
	GClosure.o \
	GError.o \
	GIOChannel.o \
	GKeyFile.o \
	GLog.o \
	GMainLoop.o \
	GObject.o \
	GOption.o \
	GParamSpec.o \
	GSignal.o \
	GType.o \
	GUtils.o \
	GValue.o \
	Glib.o \
	gperl-gtypes.o
H_FILES  = gperl-gtypes.h \
	gperl-private.h \
	gperl.h \
	gperl_marshal.h
MAN1PODS = 
MAN3PODS = $(INST_LIB)/$(FULLEXT)/index.pod \
	$(INST_LIB)/$(FULLEXT)/xsapi.pod \
	$(INST_LIB)\Glib\BookmarkFile.pod \
	$(INST_LIB)\Glib\Boxed.pod \
	$(INST_LIB)\Glib\Error.pod \
	$(INST_LIB)\Glib\Flags.pod \
	$(INST_LIB)\Glib\KeyFile.pod \
	$(INST_LIB)\Glib\Log.pod \
	$(INST_LIB)\Glib\MainLoop.pod \
	$(INST_LIB)\Glib\Markup.pod \
	$(INST_LIB)\Glib\Object.pod \
	$(INST_LIB)\Glib\OptionContext.pod \
	$(INST_LIB)\Glib\OptionGroup.pod \
	$(INST_LIB)\Glib\ParamSpec.pod \
	$(INST_LIB)\Glib\Param\Double.pod \
	$(INST_LIB)\Glib\Param\Enum.pod \
	$(INST_LIB)\Glib\Param\Flags.pod \
	$(INST_LIB)\Glib\Param\GType.pod \
	$(INST_LIB)\Glib\Param\Int.pod \
	$(INST_LIB)\Glib\Param\Int64.pod \
	$(INST_LIB)\Glib\Param\UInt.pod \
	$(INST_LIB)\Glib\Param\UInt64.pod \
	$(INST_LIB)\Glib\Signal.pod \
	$(INST_LIB)\Glib\Type.pod \
	$(INST_LIB)\Glib\Utils.pod \
	$(INST_LIB)\Glib\version.pod \
	devel.pod \
	lib/Glib.pm \
	lib/Glib/CodeGen.pm \
	lib/Glib/GenPod.pm \
	lib/Glib/MakeHelper.pm \
	lib/Glib/Object/Subclass.pm \
	lib/Glib/ParseXSDoc.pm

# Where is the Config information that we are using/depend on
CONFIGDEP = $(PERL_ARCHLIB)$(DFSEP)Config.pm $(PERL_INC)$(DFSEP)config.h

# Where to build things
INST_LIBDIR      = $(INST_LIB)
INST_ARCHLIBDIR  = $(INST_ARCHLIB)

INST_AUTODIR     = $(INST_LIB)\auto\$(FULLEXT)
INST_ARCHAUTODIR = $(INST_ARCHLIB)\auto\$(FULLEXT)

INST_STATIC      = $(INST_ARCHAUTODIR)\$(BASEEXT)$(LIB_EXT)
INST_DYNAMIC     = $(INST_ARCHAUTODIR)\$(DLBASE).$(DLEXT)
INST_BOOT        = $(INST_ARCHAUTODIR)\$(BASEEXT).bs

# Extra linker info
EXPORT_LIST        = $(BASEEXT).def
PERL_ARCHIVE       = $(PERL_INC)\libperl516.a
PERL_ARCHIVE_AFTER = 


TO_INST_PM = C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap \
	build/IFiles.pm \
	devel.pod \
	doctypes \
	gperl.h \
	gperl_marshal.h \
	lib/Glib.pm \
	lib/Glib/CodeGen.pm \
	lib/Glib/GenPod.pm \
	lib/Glib/MakeHelper.pm \
	lib/Glib/Object/Subclass.pm \
	lib/Glib/ParseXSDoc.pm

PM_TO_BLIB = build/IFiles.pm \
	$(INST_ARCHLIB)/$(FULLEXT)/Install/Files.pm \
	lib/Glib/GenPod.pm \
	$(INST_LIBDIR)/Glib/GenPod.pm \
	lib/Glib.pm \
	$(INST_LIBDIR)/Glib.pm \
	gperl.h \
	$(INST_ARCHLIB)/$(FULLEXT)/Install/gperl.h \
	lib/Glib/Object/Subclass.pm \
	$(INST_LIBDIR)/Glib/Object/Subclass.pm \
	devel.pod \
	$(INST_LIBDIR)/Glib/devel.pod \
	gperl_marshal.h \
	$(INST_ARCHLIB)/$(FULLEXT)/Install/gperl_marshal.h \
	lib/Glib/ParseXSDoc.pm \
	$(INST_LIBDIR)/Glib/ParseXSDoc.pm \
	lib/Glib/MakeHelper.pm \
	$(INST_LIBDIR)/Glib/MakeHelper.pm \
	lib/Glib/CodeGen.pm \
	$(INST_LIBDIR)/Glib/CodeGen.pm \
	doctypes \
	$(INST_ARCHLIB)/$(FULLEXT)/Install/doctypes \
	C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap \
	$(INST_ARCHLIB)/$(FULLEXT)/Install/typemap


# --- MakeMaker platform_constants section:
MM_Win32_VERSION = 6.63_02


# --- MakeMaker tool_autosplit section:
# Usage: $(AUTOSPLITFILE) FileToSplit AutoDirToSplitInto
AUTOSPLITFILE = $(ABSPERLRUN)  -e "use AutoSplit;  autosplit($$$$ARGV[0], $$$$ARGV[1], 0, 1, 1)" --



# --- MakeMaker tool_xsubpp section:

XSUBPPDIR = C:\devel\Shortcake\sandbox\perl\lib\ExtUtils
XSUBPP = $(XSUBPPDIR)$(DFSEP)xsubpp
XSUBPPRUN = $(PERLRUN) $(XSUBPP)
XSPROTOARG = -noprototypes
XSUBPPDEPS = C:\devel\Shortcake\sandbox\perl\lib\ExtUtils\typemap C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap typemap $(XSUBPP)
XSUBPPARGS = -typemap C:\devel\Shortcake\sandbox\perl\lib\ExtUtils\typemap -typemap C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap -typemap typemap
XSUBPP_EXTRA_ARGS = 


# --- MakeMaker tools_other section:
CHMOD = $(ABSPERLRUN) -MExtUtils::Command -e chmod --
CP = $(ABSPERLRUN) -MExtUtils::Command -e cp --
MV = $(ABSPERLRUN) -MExtUtils::Command -e mv --
NOOP = rem
NOECHO = @
RM_F = $(ABSPERLRUN) -MExtUtils::Command -e rm_f --
RM_RF = $(ABSPERLRUN) -MExtUtils::Command -e rm_rf --
TEST_F = $(ABSPERLRUN) -MExtUtils::Command -e test_f --
TOUCH = $(ABSPERLRUN) -MExtUtils::Command -e touch --
UMASK_NULL = umask 0
DEV_NULL = > NUL
MKPATH = $(ABSPERLRUN) -MExtUtils::Command -e mkpath --
EQUALIZE_TIMESTAMP = $(ABSPERLRUN) -MExtUtils::Command -e eqtime --
FALSE = $(ABSPERLRUN)  -e "exit 1" --
TRUE = $(ABSPERLRUN)  -e "exit 0" --
ECHO = $(ABSPERLRUN) -l -e "print qq{{@ARGV}}" --
ECHO_N = $(ABSPERLRUN)  -e "print qq{{@ARGV}}" --
UNINST = 0
VERBINST = 0
MOD_INSTALL = $(ABSPERLRUN) -MExtUtils::Install -e "install([ from_to => {{@ARGV}}, verbose => '$(VERBINST)', uninstall_shadows => '$(UNINST)', dir_mode => '$(PERM_DIR)' ]);" --
DOC_INSTALL = $(ABSPERLRUN) -MExtUtils::Command::MM -e perllocal_install --
UNINSTALL = $(ABSPERLRUN) -MExtUtils::Command::MM -e uninstall --
WARN_IF_OLD_PACKLIST = $(ABSPERLRUN) -MExtUtils::Command::MM -e warn_if_old_packlist --
MACROSTART = 
MACROEND = 
USEMAKEFILE = -f
FIXIN = pl2bat.bat


# --- MakeMaker makemakerdflt section:
makemakerdflt : all
	$(NOECHO) $(NOOP)


# --- MakeMaker dist section:
TAR = tar
TARFLAGS = cvf
ZIP = zip
ZIPFLAGS = -r
COMPRESS = gzip --best
SUFFIX = .gz
SHAR = shar
PREOP = $(NOECHO) $(NOOP)
POSTOP = $(NOECHO) $(NOOP)
TO_UNIX = $(NOECHO) $(NOOP)
CI = ci -u
RCS_LABEL = rcs -Nv$(VERSION_SYM): -q
DIST_CP = best
DIST_DEFAULT = tardist
DISTNAME = Glib
DISTVNAME = Glib-1.280


# --- MakeMaker macro section:
INST_DYNAMIC_LIB = $(INST_ARCHAUTODIR)/$(BASEEXT)$(LIB_EXT)


# --- MakeMaker depend section:


# --- MakeMaker cflags section:

CCFLAGS = -s -O2 -DWIN32 -DPERL_TEXTMODE_SCRIPTS -DPERL_IMPLICIT_CONTEXT -DPERL_IMPLICIT_SYS -fno-strict-aliasing -mms-bitfields
OPTIMIZE = -s -O2
PERLTYPE = 


# --- MakeMaker const_loadlibs section:

# Glib might depend on some other libraries:
# See ExtUtils::Liblist for details
#
EXTRALIBS = C:\devel\Shortcake\sandbox\perl\lib\libgobject-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libgthread-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libglib-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libintl.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libmoldname.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libkernel32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libuser32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libgdi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libwinspool.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libcomdlg32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libadvapi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libshell32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libole32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\liboleaut32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libnetapi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libuuid.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libws2_32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libmpr.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libwinmm.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libversion.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libodbc32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libodbccp32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libcomctl32.a
LDLOADLIBS = C:\devel\Shortcake\sandbox\perl\lib\libgobject-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libgthread-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libglib-2.0.a C:\devel\Shortcake\sandbox\perl\lib\libintl.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libmoldname.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libkernel32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libuser32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libgdi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libwinspool.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libcomdlg32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libadvapi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libshell32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libole32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\liboleaut32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libnetapi32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libuuid.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libws2_32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libmpr.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libwinmm.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libversion.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libodbc32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libodbccp32.a C:\devel\Shortcake\sandbox\c\i686-w64-mingw32\lib\libcomctl32.a
BSLOADLIBS = 


# --- MakeMaker const_cccmd section:
CCCMD = $(CC) -c $(PASTHRU_INC) $(INC) \
	$(CCFLAGS) $(OPTIMIZE) \
	$(PERLTYPE) $(MPOLLUTE) $(DEFINE_VERSION) \
	$(XS_DEFINE_VERSION) -o $@

# --- MakeMaker post_constants section:


# --- MakeMaker pasthru section:
PASTHRU = 

# --- MakeMaker special_targets section:
.SUFFIXES : .xs .c .C .cpp .i .s .cxx .cc $(OBJ_EXT)

.PHONY: all config static dynamic test linkext manifest blibdirs clean realclean disttest distdir

.USESHELL :


# --- MakeMaker c_o section:

.c.i:
	gcc -E -c $(PASTHRU_INC) $(INC) \
	$(CCFLAGS) $(OPTIMIZE) \
	$(PERLTYPE) $(MPOLLUTE) $(DEFINE_VERSION) \
	$(XS_DEFINE_VERSION) -o $@ $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.c > $*.i

.c.s:
	$(NOECHO) $(ECHO) [ CC $< ]
	$(NOECHO) $(CCCMD) -S $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.c

.c$(OBJ_EXT):
	$(NOECHO) $(ECHO) [ CC $< ]
	$(NOECHO) $(CCCMD) $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.c

.cpp$(OBJ_EXT):
	$(NOECHO) $(ECHO) [ CC $< ]
	$(NOECHO) $(CCCMD) $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.cpp

.cxx$(OBJ_EXT):
	$(NOECHO) $(ECHO) [ CC $< ]
	$(NOECHO) $(CCCMD) $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.cxx

.cc$(OBJ_EXT):
	$(NOECHO) $(ECHO) [ CC $< ]
	$(NOECHO) $(CCCMD) $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) $*.cc

# --- MakeMaker xs_c section:

.xs.c:
	$(NOECHO) $(ECHO) [ XS $< ]
	$(NOECHO) $(XSUBPPRUN) $(XSPROTOARG) $(XSUBPPARGS) $(XSUBPP_EXTRA_ARGS) $*.xs > $*.xsc && $(MV) $*.xsc $*.c

# --- MakeMaker xs_o section:


# --- MakeMaker top_targets section:
all :: pure_all
	$(NOECHO) $(NOOP)


pure_all :: config pm_to_blib subdirs linkext
	$(NOECHO) $(NOOP)

subdirs :: $(MYEXTLIB)
	$(NOECHO) $(NOOP)

config :: $(FIRST_MAKEFILE) blibdirs
	$(NOECHO) $(NOOP)

$(O_FILES): $(H_FILES)

help :
	perldoc ExtUtils::MakeMaker


# --- MakeMaker blibdirs section:
blibdirs : $(INST_LIBDIR)$(DFSEP).exists $(INST_ARCHLIB)$(DFSEP).exists $(INST_AUTODIR)$(DFSEP).exists $(INST_ARCHAUTODIR)$(DFSEP).exists $(INST_BIN)$(DFSEP).exists $(INST_SCRIPT)$(DFSEP).exists $(INST_MAN1DIR)$(DFSEP).exists $(INST_MAN3DIR)$(DFSEP).exists
	$(NOECHO) $(NOOP)

# Backwards compat with 6.18 through 6.25
blibdirs.ts : blibdirs
	$(NOECHO) $(NOOP)

$(INST_LIBDIR)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_LIBDIR)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_LIBDIR)
	$(NOECHO) $(TOUCH) $(INST_LIBDIR)$(DFSEP).exists

$(INST_ARCHLIB)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_ARCHLIB)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_ARCHLIB)
	$(NOECHO) $(TOUCH) $(INST_ARCHLIB)$(DFSEP).exists

$(INST_AUTODIR)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_AUTODIR)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_AUTODIR)
	$(NOECHO) $(TOUCH) $(INST_AUTODIR)$(DFSEP).exists

$(INST_ARCHAUTODIR)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_ARCHAUTODIR)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_ARCHAUTODIR)
	$(NOECHO) $(TOUCH) $(INST_ARCHAUTODIR)$(DFSEP).exists

$(INST_BIN)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_BIN)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_BIN)
	$(NOECHO) $(TOUCH) $(INST_BIN)$(DFSEP).exists

$(INST_SCRIPT)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_SCRIPT)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_SCRIPT)
	$(NOECHO) $(TOUCH) $(INST_SCRIPT)$(DFSEP).exists

$(INST_MAN1DIR)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_MAN1DIR)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_MAN1DIR)
	$(NOECHO) $(TOUCH) $(INST_MAN1DIR)$(DFSEP).exists

$(INST_MAN3DIR)$(DFSEP).exists :: Makefile.PL
	$(NOECHO) $(MKPATH) $(INST_MAN3DIR)
	$(NOECHO) $(CHMOD) $(PERM_DIR) $(INST_MAN3DIR)
	$(NOECHO) $(TOUCH) $(INST_MAN3DIR)$(DFSEP).exists



# --- MakeMaker linkext section:

linkext :: $(LINKTYPE)
	$(NOECHO) $(NOOP)


# --- MakeMaker dlsyms section:

Glib.def: Makefile.PL
	$(PERLRUN) -MExtUtils::Mksymlists \
     -e "Mksymlists('NAME'=>\"Glib\", 'DLBASE' => '$(BASEEXT)', 'DL_FUNCS' => { Glib=>[] }, 'FUNCLIST' => [q[SvGChar], q[SvGKeyFile], q[SvGParamFlags], q[SvGParamSpec], q[SvGSignalFlags], q[SvGInt64], q[SvGUInt64], q[_gperl_attach_mg], q[_gperl_call_XS], q[_gperl_find_mg], q[_gperl_remove_mg], q[gperl_alloc_temp], q[gperl_argv_free], q[gperl_argv_new], q[gperl_argv_update], q[gperl_boxed_package_from_type], q[gperl_boxed_type_from_package], q[gperl_callback_destroy], q[gperl_callback_invoke], q[gperl_callback_new], q[gperl_closure_new], q[gperl_closure_new_with_marshaller], q[gperl_convert_back_enum], q[gperl_convert_back_enum_pass_unknown], q[gperl_convert_back_flags], q[gperl_convert_enum], q[gperl_convert_flag_one], q[gperl_convert_flags], q[gperl_croak_gerror], q[gperl_default_boxed_wrapper_class], q[gperl_filename_from_sv], q[gperl_format_variable_for_output], q[gperl_fundamental_package_from_type], q[gperl_fundamental_type_from_package], q[gperl_gerror_from_sv], q[gperl_get_boxed_check], q[gperl_get_object], q[gperl_get_object_check], q[gperl_handle_logs_for], q[gperl_hv_take_sv], q[gperl_install_exception_handler], q[gperl_new_boxed], q[gperl_new_boxed_copy], q[gperl_new_object], q[gperl_object_check_type], q[gperl_object_package_from_type], q[gperl_object_set_no_warn_unreg_subclass], q[gperl_object_stash_from_type], q[gperl_object_type_from_package], q[gperl_option_context_get_type], q[gperl_option_group_get_type], q[gperl_package_from_type], q[gperl_param_spec_package_from_type], q[gperl_param_spec_type_from_package], q[gperl_prepend_isa], q[gperl_register_boxed], q[gperl_register_boxed_alias], q[gperl_register_boxed_synonym], q[gperl_register_error_domain], q[gperl_register_fundamental], q[gperl_register_fundamental_alias], q[gperl_register_object], q[gperl_register_object_alias], q[gperl_register_param_spec], q[gperl_register_sink_func], q[gperl_remove_exception_handler], q[gperl_run_exception_handlers], q[gperl_set_isa], q[gperl_signal_connect], q[gperl_signal_set_marshaller_for], q[gperl_str_eq], q[gperl_str_hash], q[gperl_sv_copy], q[gperl_sv_is_defined], q[gperl_sv_free], q[gperl_sv_from_filename], q[gperl_sv_from_gerror], q[gperl_sv_from_value], q[gperl_sv_get_type], q[gperl_try_convert_enum], q[gperl_try_convert_flag], q[gperl_type_class], q[gperl_type_from_package], q[gperl_value_from_sv], q[newSVGChar], q[newSVGParamFlags], q[newSVGParamSpec], q[newSVGSignalFlags], q[newSVGSignalInvocationHint], q[newSVGSignalQuery], q[newSVGInt64], q[newSVGUInt64]], 'IMPORTS' => {  }, 'DL_VARS' => []);"


# --- MakeMaker dynamic section:

dynamic :: $(FIRST_MAKEFILE) $(INST_DYNAMIC) $(INST_BOOT)
	$(NOECHO) $(NOOP)


# --- MakeMaker dynamic_bs section:
BOOTSTRAP = $(BASEEXT).bs

# As Mkbootstrap might not write a file (if none is required)
# we use touch to prevent make continually trying to remake it.
# The DynaLoader only reads a non-empty file.
$(BOOTSTRAP) : $(FIRST_MAKEFILE) $(BOOTDEP) $(INST_ARCHAUTODIR)$(DFSEP).exists
	$(NOECHO) $(ECHO) "Running Mkbootstrap for $(NAME) ($(BSLOADLIBS))"
	$(NOECHO) $(PERLRUN) \
		"-MExtUtils::Mkbootstrap" \
		-e "Mkbootstrap('$(BASEEXT)','$(BSLOADLIBS)');"
	$(NOECHO) $(TOUCH) $@
	$(CHMOD) $(PERM_RW) $@

$(INST_BOOT) : $(BOOTSTRAP) $(INST_ARCHAUTODIR)$(DFSEP).exists
	$(NOECHO) $(RM_RF) $@
	- $(CP) $(BOOTSTRAP) $@
	$(CHMOD) $(PERM_RW) $@


# --- MakeMaker dynamic_lib section:

# This section creates the dynamically loadable $(INST_DYNAMIC)
# from $(OBJECT) and possibly $(MYEXTLIB).
OTHERLDFLAGS = 
INST_DYNAMIC_DEP = 

$(INST_DYNAMIC): $(OBJECT) $(MYEXTLIB) $(BOOTSTRAP) $(INST_ARCHAUTODIR)$(DFSEP).exists $(EXPORT_LIST) $(PERL_ARCHIVE) $(INST_DYNAMIC_DEP)
	dlltool --def $(EXPORT_LIST) --output-exp dll.exp
	$(NOECHO) $(ECHO) [ LD $@ ]
	$(NOECHO) $(LD) -o $@ -Wl,--base-file -Wl,dll.base $(LDDLFLAGS) $(LDFROM) $(OTHERLDFLAGS) $(MYEXTLIB) $(PERL_ARCHIVE) $(LDLOADLIBS) dll.exp
	dlltool --def $(EXPORT_LIST) --base-file dll.base --output-exp dll.exp
	$(NOECHO) $(ECHO) [ LD $@ ]
	$(NOECHO) $(LD) -o $@ $(LDDLFLAGS) $(LDFROM) $(OTHERLDFLAGS) $(MYEXTLIB) $(PERL_ARCHIVE) $(LDLOADLIBS) dll.exp 
	$(CHMOD) $(PERM_RWX) $@

# --- MakeMaker static section:

## $(INST_PM) has been moved to the all: target.
## It remains here for awhile to allow for old usage: "make static"
static :: $(FIRST_MAKEFILE) $(INST_STATIC)
	$(NOECHO) $(NOOP)


# --- MakeMaker static_lib section:
# This isn't actually a static lib, it just has the same name on Win32.
$(INST_DYNAMIC_LIB): $(INST_DYNAMIC)
	dlltool --def $(EXPORT_LIST) --output-lib $@ --dllname $(BASEEXT).$(SO) $(INST_DYNAMIC)

dynamic:: $(INST_DYNAMIC_LIB)

# --- MakeMaker manifypods section:

POD2MAN_EXE = $(PERLRUN) "-MExtUtils::Command::MM" -e pod2man "--"
POD2MAN = $(POD2MAN_EXE)


manifypods : pure_all  \
	$(INST_LIB)\Glib\Boxed.pod \
	$(INST_LIB)\Glib\Signal.pod \
	$(INST_LIB)\Glib\Param\Int.pod \
	$(INST_LIB)\Glib\Log.pod \
	$(INST_LIB)/$(FULLEXT)/xsapi.pod \
	lib/Glib/Object/Subclass.pm \
	$(INST_LIB)\Glib\Param\UInt.pod \
	$(INST_LIB)\Glib\Param\GType.pod \
	$(INST_LIB)\Glib\Param\UInt64.pod \
	$(INST_LIB)\Glib\Object.pod \
	$(INST_LIB)\Glib\Utils.pod \
	$(INST_LIB)\Glib\Flags.pod \
	$(INST_LIB)\Glib\BookmarkFile.pod \
	$(INST_LIB)\Glib\version.pod \
	$(INST_LIB)\Glib\Param\Flags.pod \
	$(INST_LIB)/$(FULLEXT)/index.pod \
	$(INST_LIB)\Glib\ParamSpec.pod \
	$(INST_LIB)\Glib\Type.pod \
	$(INST_LIB)\Glib\Error.pod \
	$(INST_LIB)\Glib\Param\Int64.pod \
	$(INST_LIB)\Glib\MainLoop.pod \
	lib/Glib/GenPod.pm \
	$(INST_LIB)\Glib\KeyFile.pod \
	$(INST_LIB)\Glib\OptionGroup.pod \
	lib/Glib.pm \
	$(INST_LIB)\Glib\Param\Double.pod \
	$(INST_LIB)\Glib\Param\Enum.pod \
	$(INST_LIB)\Glib\OptionContext.pod \
	devel.pod \
	lib/Glib/MakeHelper.pm \
	lib/Glib/ParseXSDoc.pm \
	lib/Glib/CodeGen.pm \
	$(INST_LIB)\Glib\Markup.pod
	$(NOECHO) $(POD2MAN) --section=3 --perm_rw=$(PERM_RW) \
	  $(INST_LIB)\Glib\Boxed.pod $(INST_MAN3DIR)/Glib::Boxed.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Signal.pod $(INST_MAN3DIR)/Glib::Signal.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\Int.pod $(INST_MAN3DIR)/Glib::Param::Int.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Log.pod $(INST_MAN3DIR)/Glib::Log.$(MAN3EXT) \
	  $(INST_LIB)/$(FULLEXT)/xsapi.pod $(INST_MAN3DIR)/Glib::xsapi.$(MAN3EXT) \
	  lib/Glib/Object/Subclass.pm $(INST_MAN3DIR)/Glib::Object::Subclass.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\UInt.pod $(INST_MAN3DIR)/Glib::Param::UInt.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\GType.pod $(INST_MAN3DIR)/Glib::Param::GType.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\UInt64.pod $(INST_MAN3DIR)/Glib::Param::UInt64.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Object.pod $(INST_MAN3DIR)/Glib::Object.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Utils.pod $(INST_MAN3DIR)/Glib::Utils.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Flags.pod $(INST_MAN3DIR)/Glib::Flags.$(MAN3EXT) \
	  $(INST_LIB)\Glib\BookmarkFile.pod $(INST_MAN3DIR)/Glib::BookmarkFile.$(MAN3EXT) \
	  $(INST_LIB)\Glib\version.pod $(INST_MAN3DIR)/Glib::version.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\Flags.pod $(INST_MAN3DIR)/Glib::Param::Flags.$(MAN3EXT) \
	  $(INST_LIB)/$(FULLEXT)/index.pod $(INST_MAN3DIR)/$(NAME)::index.$(MAN3EXT) \
	  $(INST_LIB)\Glib\ParamSpec.pod $(INST_MAN3DIR)/Glib::ParamSpec.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Type.pod $(INST_MAN3DIR)/Glib::Type.$(MAN3EXT) 
	$(NOECHO) $(POD2MAN) --section=3 --perm_rw=$(PERM_RW) \
	  $(INST_LIB)\Glib\Error.pod $(INST_MAN3DIR)/Glib::Error.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\Int64.pod $(INST_MAN3DIR)/Glib::Param::Int64.$(MAN3EXT) \
	  $(INST_LIB)\Glib\MainLoop.pod $(INST_MAN3DIR)/Glib::MainLoop.$(MAN3EXT) \
	  lib/Glib/GenPod.pm $(INST_MAN3DIR)/Glib::GenPod.$(MAN3EXT) \
	  $(INST_LIB)\Glib\KeyFile.pod $(INST_MAN3DIR)/Glib::KeyFile.$(MAN3EXT) \
	  $(INST_LIB)\Glib\OptionGroup.pod $(INST_MAN3DIR)/Glib::OptionGroup.$(MAN3EXT) \
	  lib/Glib.pm $(INST_MAN3DIR)/Glib.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\Double.pod $(INST_MAN3DIR)/Glib::Param::Double.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Param\Enum.pod $(INST_MAN3DIR)/Glib::Param::Enum.$(MAN3EXT) \
	  $(INST_LIB)\Glib\OptionContext.pod $(INST_MAN3DIR)/Glib::OptionContext.$(MAN3EXT) \
	  devel.pod $(INST_MAN3DIR)/Glib::devel.$(MAN3EXT) \
	  lib/Glib/MakeHelper.pm $(INST_MAN3DIR)/Glib::MakeHelper.$(MAN3EXT) \
	  lib/Glib/ParseXSDoc.pm $(INST_MAN3DIR)/Glib::ParseXSDoc.$(MAN3EXT) \
	  lib/Glib/CodeGen.pm $(INST_MAN3DIR)/Glib::CodeGen.$(MAN3EXT) \
	  $(INST_LIB)\Glib\Markup.pod $(INST_MAN3DIR)/Glib::Markup.$(MAN3EXT) 




# --- MakeMaker processPL section:


# --- MakeMaker installbin section:


# --- MakeMaker subdirs section:

# none

# --- MakeMaker clean_subdirs section:
clean_subdirs :
	$(NOECHO) $(NOOP)


# --- MakeMaker clean section:

# Delete temporary files but do not touch installed files. We don't delete
# the Makefile here so a later make realclean still has a makefile to use.

clean :: clean_subdirs
	- $(RM_F) \
	  GType.c Glib.c \
	  core.[0-9] $(BASEEXT).bso \
	  pm_to_blib.ts GIOChannel.c \
	  core.[0-9][0-9][0-9][0-9] MYMETA.yml \
	  GLog.c GParamSpec.c \
	  perl$(EXE_EXT) tmon.out \
	  GKeyFile.c *$(OBJ_EXT) \
	  pm_to_blib GValue.c \
	  GError.c GUtils.c \
	  GBoxed.c blibdirs.ts \
	  *perl.core core.*perl.*.? \
	  $(BASEEXT).def core.[0-9][0-9][0-9] \
	  mon.out lib$(BASEEXT).def \
	  perl.exe perlmain.c \
	  GMainLoop.c GSignal.c \
	  so_locations $(BASEEXT).exp \
	  *$(LIB_EXT) core \
	  core.[0-9][0-9] $(INST_ARCHAUTODIR)\extralibs.ld \
	  MYMETA.json $(BASEEXT).x \
	  $(BOOTSTRAP) GObject.c \
	  $(INST_ARCHAUTODIR)\extralibs.all GOption.c \
	  GClosure.c GBookmarkFile.c \
	  core.[0-9][0-9][0-9][0-9][0-9] $(MAKE_APERL_FILE) \
	  perl 
	- $(RM_RF) \
	  GParamSpec$(OBJ_EXT) GOption$(OBJ_EXT) \
	  GKeyFile$(OBJ_EXT) GType$(OBJ_EXT) \
	  GError$(OBJ_EXT) GUtils$(OBJ_EXT) \
	  dll.exp GObject$(OBJ_EXT) \
	  GValue$(OBJ_EXT) GLog$(OBJ_EXT) \
	  GClosure$(OBJ_EXT) GSignal$(OBJ_EXT) \
	  dll.base GBoxed$(OBJ_EXT) \
	  GIOChannel$(OBJ_EXT) GBookmarkFile$(OBJ_EXT) \
	  gperl-gtypes$(OBJ_EXT) Glib$(OBJ_EXT) \
	  GMainLoop$(OBJ_EXT) blib 
	- $(MV) $(FIRST_MAKEFILE) $(MAKEFILE_OLD) $(DEV_NULL)


# --- MakeMaker realclean_subdirs section:
realclean_subdirs :
	$(NOECHO) $(NOOP)


# --- MakeMaker realclean section:
# Delete temporary files (via clean) and also delete dist files
realclean purge ::  clean realclean_subdirs
	- $(RM_F) \
	  $(OBJECT) $(MAKEFILE_OLD) \
	  $(FIRST_MAKEFILE) 
	- $(RM_RF) \
	  $(DISTVNAME) 


# --- MakeMaker metafile section:
metafile : create_distdir
	$(NOECHO) $(ECHO) Generating META.yml
	$(NOECHO) $(ECHO) --- > META_new.yml
	$(NOECHO) $(ECHO) "abstract: 'Perl wrappers for the GLib utility and Object libraries'" >> META_new.yml
	$(NOECHO) $(ECHO) author: >> META_new.yml
	$(NOECHO) $(ECHO) "  - 'gtk2-perl Team <gtk-perl-list at gnome dot org>'" >> META_new.yml
	$(NOECHO) $(ECHO) "build_requires: {{}}" >> META_new.yml
	$(NOECHO) $(ECHO) configure_requires: >> META_new.yml
	$(NOECHO) $(ECHO) "  ExtUtils::Depends: 0.300" >> META_new.yml
	$(NOECHO) $(ECHO) "  ExtUtils::PkgConfig: 1.000" >> META_new.yml
	$(NOECHO) $(ECHO) "dynamic_config: 1" >> META_new.yml
	$(NOECHO) $(ECHO) "generated_by: 'ExtUtils::MakeMaker version 6.6302, CPAN::Meta::Converter version 2.120921'" >> META_new.yml
	$(NOECHO) $(ECHO) "license: lgpl" >> META_new.yml
	$(NOECHO) $(ECHO) meta-spec: >> META_new.yml
	$(NOECHO) $(ECHO) "  url: http://module-build.sourceforge.net/META-spec-v1.4.html" >> META_new.yml
	$(NOECHO) $(ECHO) "  version: 1.4" >> META_new.yml
	$(NOECHO) $(ECHO) "name: Glib" >> META_new.yml
	$(NOECHO) $(ECHO) no_index: >> META_new.yml
	$(NOECHO) $(ECHO) "  directory:" >> META_new.yml
	$(NOECHO) $(ECHO) "    - t" >> META_new.yml
	$(NOECHO) $(ECHO) "    - inc" >> META_new.yml
	$(NOECHO) $(ECHO) "  file:" >> META_new.yml
	$(NOECHO) $(ECHO) "    - Glib.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GError.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GUtils.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GLog.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GType.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GBoxed.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GObject.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GValue.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GClosure.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GSignal.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GMainLoop.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GIOChannel.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GParamSpec.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GKeyFile.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GOption.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - GBookmarkFile.xs" >> META_new.yml
	$(NOECHO) $(ECHO) "    - Makefile.PL" >> META_new.yml
	$(NOECHO) $(ECHO) "    - xsapi.pod.head" >> META_new.yml
	$(NOECHO) $(ECHO) "    - xsapi.pod.foot" >> META_new.yml
	$(NOECHO) $(ECHO) "  package:" >> META_new.yml
	$(NOECHO) $(ECHO) "    - MY" >> META_new.yml
	$(NOECHO) $(ECHO) resources: >> META_new.yml
	$(NOECHO) $(ECHO) "  bugtracker: http://rt.cpan.org/Public/Dist/Display.html?Name=Glib" >> META_new.yml
	$(NOECHO) $(ECHO) "  homepage: http://gtk2-perl.sourceforge.net" >> META_new.yml
	$(NOECHO) $(ECHO) "  license: http://www.gnu.org/licenses/lgpl-2.1.html" >> META_new.yml
	$(NOECHO) $(ECHO) "  repository: git://git.gnome.org/perl-Glib" >> META_new.yml
	$(NOECHO) $(ECHO) "  x_MailingList: https://mail.gnome.org/mailman/listinfo/gtk-perl-list" >> META_new.yml
	$(NOECHO) $(ECHO) "version: 1.280" >> META_new.yml
	-$(NOECHO) $(MV) META_new.yml $(DISTVNAME)/META.yml
	$(NOECHO) $(ECHO) Generating META.json
	$(NOECHO) $(ECHO) {{ > META_new.json
	$(NOECHO) $(ECHO) "   \"abstract\" : \"Perl wrappers for the GLib utility and Object libraries\"," >> META_new.json
	$(NOECHO) $(ECHO) "   \"author\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "      \"gtk2-perl Team ^<gtk-perl-list at gnome dot org^>\"" >> META_new.json
	$(NOECHO) $(ECHO) "   ]," >> META_new.json
	$(NOECHO) $(ECHO) "   \"dynamic_config\" : 1," >> META_new.json
	$(NOECHO) $(ECHO) "   \"generated_by\" : \"ExtUtils::MakeMaker version 6.6302, CPAN::Meta::Converter version 2.120921\"," >> META_new.json
	$(NOECHO) $(ECHO) "   \"license\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "      \"lgpl_2_1\"" >> META_new.json
	$(NOECHO) $(ECHO) "   ]," >> META_new.json
	$(NOECHO) $(ECHO) "   \"meta-spec\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "      \"url\" : \"http://search.cpan.org/perldoc?CPAN::Meta::Spec\"," >> META_new.json
	$(NOECHO) $(ECHO) "      \"version\" : \"2\"" >> META_new.json
	$(NOECHO) $(ECHO) "   }}," >> META_new.json
	$(NOECHO) $(ECHO) "   \"name\" : \"Glib\"," >> META_new.json
	$(NOECHO) $(ECHO) "   \"no_index\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "      \"directory\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "         \"t\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"inc\"" >> META_new.json
	$(NOECHO) $(ECHO) "      ]," >> META_new.json
	$(NOECHO) $(ECHO) "      \"file\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "         \"Glib.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GError.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GUtils.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GLog.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GType.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GBoxed.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GObject.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GValue.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GClosure.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GSignal.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GMainLoop.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GIOChannel.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GParamSpec.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GKeyFile.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GOption.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"GBookmarkFile.xs\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"Makefile.PL\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"xsapi.pod.head\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"xsapi.pod.foot\"" >> META_new.json
	$(NOECHO) $(ECHO) "      ]," >> META_new.json
	$(NOECHO) $(ECHO) "      \"package\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "         \"MY\"" >> META_new.json
	$(NOECHO) $(ECHO) "      ]" >> META_new.json
	$(NOECHO) $(ECHO) "   }}," >> META_new.json
	$(NOECHO) $(ECHO) "   \"prereqs\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "      \"configure\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "         \"requires\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "            \"ExtUtils::Depends\" : \"0.300\"," >> META_new.json
	$(NOECHO) $(ECHO) "            \"ExtUtils::PkgConfig\" : \"1.000\"" >> META_new.json
	$(NOECHO) $(ECHO) "         }}" >> META_new.json
	$(NOECHO) $(ECHO) "      }}" >> META_new.json
	$(NOECHO) $(ECHO) "   }}," >> META_new.json
	$(NOECHO) $(ECHO) "   \"release_status\" : \"stable\"," >> META_new.json
	$(NOECHO) $(ECHO) "   \"resources\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "      \"bugtracker\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "         \"mailto\" : \"bug-Glib [at] rt.cpan.org\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"web\" : \"http://rt.cpan.org/Public/Dist/Display.html?Name=Glib\"" >> META_new.json
	$(NOECHO) $(ECHO) "      }}," >> META_new.json
	$(NOECHO) $(ECHO) "      \"homepage\" : \"http://gtk2-perl.sourceforge.net\"," >> META_new.json
	$(NOECHO) $(ECHO) "      \"license\" : [" >> META_new.json
	$(NOECHO) $(ECHO) "         \"http://www.gnu.org/licenses/lgpl-2.1.html\"" >> META_new.json
	$(NOECHO) $(ECHO) "      ]," >> META_new.json
	$(NOECHO) $(ECHO) "      \"repository\" : {{" >> META_new.json
	$(NOECHO) $(ECHO) "         \"type\" : \"git\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"url\" : \"git://git.gnome.org/perl-Glib\"," >> META_new.json
	$(NOECHO) $(ECHO) "         \"web\" : \"http://git.gnome.org/browse/perl-Glib\"" >> META_new.json
	$(NOECHO) $(ECHO) "      }}," >> META_new.json
	$(NOECHO) $(ECHO) "      \"x_MailingList\" : \"https://mail.gnome.org/mailman/listinfo/gtk-perl-list\"" >> META_new.json
	$(NOECHO) $(ECHO) "   }}," >> META_new.json
	$(NOECHO) $(ECHO) "   \"version\" : \"1.280\"" >> META_new.json
	$(NOECHO) $(ECHO) }} >> META_new.json
	-$(NOECHO) $(MV) META_new.json $(DISTVNAME)/META.json


# --- MakeMaker signature section:
signature :
	cpansign -s


# --- MakeMaker dist_basics section:
distclean :: realclean distcheck
	$(NOECHO) $(NOOP)

distcheck :
	$(PERLRUN) "-MExtUtils::Manifest=fullcheck" -e fullcheck

skipcheck :
	$(PERLRUN) "-MExtUtils::Manifest=skipcheck" -e skipcheck

manifest :
	$(PERLRUN) "-MExtUtils::Manifest=mkmanifest" -e mkmanifest

veryclean : realclean
	$(RM_F) *~ */*~ *.orig */*.orig *.bak */*.bak *.old */*.old 



# --- MakeMaker dist_core section:

dist : $(DIST_DEFAULT) $(FIRST_MAKEFILE)
	$(NOECHO) $(ABSPERLRUN) -l -e "print 'Warning: Makefile possibly out of date with $(VERSION_FROM)'\
    if -e '$(VERSION_FROM)' and -M '$(VERSION_FROM)' < -M '$(FIRST_MAKEFILE)';" --

tardist : $(DISTVNAME).tar$(SUFFIX)
	$(NOECHO) $(NOOP)

uutardist : $(DISTVNAME).tar$(SUFFIX)
	uuencode $(DISTVNAME).tar$(SUFFIX) $(DISTVNAME).tar$(SUFFIX) > $(DISTVNAME).tar$(SUFFIX)_uu

$(DISTVNAME).tar$(SUFFIX) : distdir
	$(PREOP)
	$(TO_UNIX)
	$(TAR) $(TARFLAGS) $(DISTVNAME).tar $(DISTVNAME)
	$(RM_RF) $(DISTVNAME)
	$(COMPRESS) $(DISTVNAME).tar
	$(POSTOP)

zipdist : $(DISTVNAME).zip
	$(NOECHO) $(NOOP)

$(DISTVNAME).zip : distdir
	$(PREOP)
	$(ZIP) $(ZIPFLAGS) $(DISTVNAME).zip $(DISTVNAME)
	$(RM_RF) $(DISTVNAME)
	$(POSTOP)

shdist : distdir
	$(PREOP)
	$(SHAR) $(DISTVNAME) > $(DISTVNAME).shar
	$(RM_RF) $(DISTVNAME)
	$(POSTOP)


# --- MakeMaker distdir section:
create_distdir :
	$(RM_RF) $(DISTVNAME)
	$(PERLRUN) "-MExtUtils::Manifest=manicopy,maniread" \
		-e "manicopy(maniread(),'$(DISTVNAME)', '$(DIST_CP)');"

distdir : create_distdir distmeta 
	$(NOECHO) $(NOOP)



# --- MakeMaker dist_test section:
disttest : distdir
	cd $(DISTVNAME) && $(ABSPERLRUN) Makefile.PL 
	cd $(DISTVNAME) && $(MAKE) $(PASTHRU)
	cd $(DISTVNAME) && $(MAKE) test $(PASTHRU)



# --- MakeMaker dist_ci section:

ci :
	$(PERLRUN) "-MExtUtils::Manifest=maniread" \
	  -e "@all = keys %{ maniread() };" \
	  -e "print(qq{Executing $(CI) @all\n}); system(qq{$(CI) @all});" \
	  -e "print(qq{Executing $(RCS_LABEL) ...\n}); system(qq{$(RCS_LABEL) @all});"


# --- MakeMaker distmeta section:
distmeta : create_distdir metafile
	$(NOECHO) cd $(DISTVNAME) && $(ABSPERLRUN) -MExtUtils::Manifest=maniadd -e "exit unless -e q{{META.yml}};\
eval {{ maniadd({{q{{META.yml}} => q{{Module YAML meta-data (added by MakeMaker)}}}}) }}\
    or print \"Could not add META.yml to MANIFEST: $$$${{'^@'}}\n\"" --
	$(NOECHO) cd $(DISTVNAME) && $(ABSPERLRUN) -MExtUtils::Manifest=maniadd -e "exit unless -f q{{META.json}};\
eval {{ maniadd({{q{{META.json}} => q{{Module JSON meta-data (added by MakeMaker)}}}}) }}\
    or print \"Could not add META.json to MANIFEST: $$$${{'^@'}}\n\"" --



# --- MakeMaker distsignature section:
distsignature : create_distdir
	$(NOECHO) cd $(DISTVNAME) && $(ABSPERLRUN) -MExtUtils::Manifest=maniadd -e "eval {{ maniadd({{q{{SIGNATURE}} => q{{Public-key signature (added by MakeMaker)}}}}) }} \
    or print \"Could not add SIGNATURE to MANIFEST: $$$${{'^@'}}\n\"" --
	$(NOECHO) cd $(DISTVNAME) && $(TOUCH) SIGNATURE
	cd $(DISTVNAME) && cpansign -s



# --- MakeMaker install section:

install :: pure_install doc_install
	$(NOECHO) $(NOOP)

install_perl :: pure_perl_install doc_perl_install
	$(NOECHO) $(NOOP)

install_site :: pure_site_install doc_site_install
	$(NOECHO) $(NOOP)

install_vendor :: pure_vendor_install doc_vendor_install
	$(NOECHO) $(NOOP)

pure_install :: pure_$(INSTALLDIRS)_install
	$(NOECHO) $(NOOP)

doc_install :: doc_$(INSTALLDIRS)_install
	$(NOECHO) $(NOOP)

pure__install : pure_site_install
	$(NOECHO) $(ECHO) INSTALLDIRS not defined, defaulting to INSTALLDIRS=site

doc__install : doc_site_install
	$(NOECHO) $(ECHO) INSTALLDIRS not defined, defaulting to INSTALLDIRS=site

pure_perl_install :: all
	$(NOECHO) $(MOD_INSTALL) \
		read $(PERL_ARCHLIB)\auto\$(FULLEXT)\.packlist \
		write $(DESTINSTALLARCHLIB)\auto\$(FULLEXT)\.packlist \
		$(INST_LIB) $(DESTINSTALLPRIVLIB) \
		$(INST_ARCHLIB) $(DESTINSTALLARCHLIB) \
		$(INST_BIN) $(DESTINSTALLBIN) \
		$(INST_SCRIPT) $(DESTINSTALLSCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLMAN3DIR)
	$(NOECHO) $(WARN_IF_OLD_PACKLIST) \
		$(SITEARCHEXP)\auto\$(FULLEXT)


pure_site_install :: all
	$(NOECHO) $(MOD_INSTALL) \
		read $(SITEARCHEXP)\auto\$(FULLEXT)\.packlist \
		write $(DESTINSTALLSITEARCH)\auto\$(FULLEXT)\.packlist \
		$(INST_LIB) $(DESTINSTALLSITELIB) \
		$(INST_ARCHLIB) $(DESTINSTALLSITEARCH) \
		$(INST_BIN) $(DESTINSTALLSITEBIN) \
		$(INST_SCRIPT) $(DESTINSTALLSITESCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLSITEMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLSITEMAN3DIR)
	$(NOECHO) $(WARN_IF_OLD_PACKLIST) \
		$(PERL_ARCHLIB)\auto\$(FULLEXT)

pure_vendor_install :: all
	$(NOECHO) $(MOD_INSTALL) \
		read $(VENDORARCHEXP)\auto\$(FULLEXT)\.packlist \
		write $(DESTINSTALLVENDORARCH)\auto\$(FULLEXT)\.packlist \
		$(INST_LIB) $(DESTINSTALLVENDORLIB) \
		$(INST_ARCHLIB) $(DESTINSTALLVENDORARCH) \
		$(INST_BIN) $(DESTINSTALLVENDORBIN) \
		$(INST_SCRIPT) $(DESTINSTALLVENDORSCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLVENDORMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLVENDORMAN3DIR)

doc_perl_install :: all
	$(NOECHO) $(ECHO) Appending installation info to $(DESTINSTALLARCHLIB)/perllocal.pod
	-$(NOECHO) $(MKPATH) $(DESTINSTALLARCHLIB)
	-$(NOECHO) $(DOC_INSTALL) \
		"Module" "$(NAME)" \
		"installed into" "$(INSTALLPRIVLIB)" \
		LINKTYPE "$(LINKTYPE)" \
		VERSION "$(VERSION)" \
		EXE_FILES "$(EXE_FILES)" \
		>> $(DESTINSTALLARCHLIB)\perllocal.pod

doc_site_install :: all
	$(NOECHO) $(ECHO) Appending installation info to $(DESTINSTALLARCHLIB)/perllocal.pod
	-$(NOECHO) $(MKPATH) $(DESTINSTALLARCHLIB)
	-$(NOECHO) $(DOC_INSTALL) \
		"Module" "$(NAME)" \
		"installed into" "$(INSTALLSITELIB)" \
		LINKTYPE "$(LINKTYPE)" \
		VERSION "$(VERSION)" \
		EXE_FILES "$(EXE_FILES)" \
		>> $(DESTINSTALLARCHLIB)\perllocal.pod

doc_vendor_install :: all
	$(NOECHO) $(ECHO) Appending installation info to $(DESTINSTALLARCHLIB)/perllocal.pod
	-$(NOECHO) $(MKPATH) $(DESTINSTALLARCHLIB)
	-$(NOECHO) $(DOC_INSTALL) \
		"Module" "$(NAME)" \
		"installed into" "$(INSTALLVENDORLIB)" \
		LINKTYPE "$(LINKTYPE)" \
		VERSION "$(VERSION)" \
		EXE_FILES "$(EXE_FILES)" \
		>> $(DESTINSTALLARCHLIB)\perllocal.pod


uninstall :: uninstall_from_$(INSTALLDIRS)dirs
	$(NOECHO) $(NOOP)

uninstall_from_perldirs ::
	$(NOECHO) $(UNINSTALL) $(PERL_ARCHLIB)\auto\$(FULLEXT)\.packlist

uninstall_from_sitedirs ::
	$(NOECHO) $(UNINSTALL) $(SITEARCHEXP)\auto\$(FULLEXT)\.packlist

uninstall_from_vendordirs ::
	$(NOECHO) $(UNINSTALL) $(VENDORARCHEXP)\auto\$(FULLEXT)\.packlist


# --- MakeMaker force section:
# Phony target to force checking subdirectories.
FORCE :
	$(NOECHO) $(NOOP)


# --- MakeMaker perldepend section:

PERL_HDRS = \
	$(PERL_INC)/EXTERN.h		\
	$(PERL_INC)/INTERN.h		\
	$(PERL_INC)/XSUB.h		\
	$(PERL_INC)/av.h		\
	$(PERL_INC)/config.h		\
	$(PERL_INC)/cop.h		\
	$(PERL_INC)/cv.h		\
	$(PERL_INC)/dosish.h		\
	$(PERL_INC)/embed.h		\
	$(PERL_INC)/embedvar.h		\
	$(PERL_INC)/fakethr.h		\
	$(PERL_INC)/form.h		\
	$(PERL_INC)/gv.h		\
	$(PERL_INC)/handy.h		\
	$(PERL_INC)/hv.h		\
	$(PERL_INC)/intrpvar.h		\
	$(PERL_INC)/iperlsys.h		\
	$(PERL_INC)/keywords.h		\
	$(PERL_INC)/mg.h		\
	$(PERL_INC)/nostdio.h		\
	$(PERL_INC)/op.h		\
	$(PERL_INC)/opcode.h		\
	$(PERL_INC)/patchlevel.h	\
	$(PERL_INC)/perl.h		\
	$(PERL_INC)/perlio.h		\
	$(PERL_INC)/perlsdio.h		\
	$(PERL_INC)/perlsfio.h		\
	$(PERL_INC)/perlvars.h		\
	$(PERL_INC)/perly.h		\
	$(PERL_INC)/pp.h		\
	$(PERL_INC)/pp_proto.h		\
	$(PERL_INC)/proto.h		\
	$(PERL_INC)/regcomp.h		\
	$(PERL_INC)/regexp.h		\
	$(PERL_INC)/regnodes.h		\
	$(PERL_INC)/scope.h		\
	$(PERL_INC)/sv.h		\
	$(PERL_INC)/thread.h		\
	$(PERL_INC)/unixish.h		\
	$(PERL_INC)/util.h

$(OBJECT) : $(PERL_HDRS)

GIOChannel.c GKeyFile.c GUtils.c GError.c GBoxed.c GObject.c GMainLoop.c GValue.c Glib.c GOption.c GSignal.c GType.c GLog.c GClosure.c GBookmarkFile.c GParamSpec.c : $(XSUBPPDEPS)


# --- MakeMaker makefile section:

$(OBJECT) : $(FIRST_MAKEFILE)

# We take a very conservative approach here, but it's worth it.
# We move Makefile to Makefile.old here to avoid gnu make looping.
$(FIRST_MAKEFILE) : Makefile.PL $(CONFIGDEP)
	$(NOECHO) $(ECHO) "Makefile out-of-date with respect to $?"
	$(NOECHO) $(ECHO) "Cleaning current config before rebuilding Makefile..."
	-$(NOECHO) $(RM_F) $(MAKEFILE_OLD)
	-$(NOECHO) $(MV)   $(FIRST_MAKEFILE) $(MAKEFILE_OLD)
	- $(MAKE) $(USEMAKEFILE) $(MAKEFILE_OLD) clean $(DEV_NULL)
	$(PERLRUN) Makefile.PL 
	$(NOECHO) $(ECHO) "==> Your Makefile has been rebuilt. <=="
	$(NOECHO) $(ECHO) "==> Please rerun the $(MAKE) command.  <=="
	$(FALSE)



# --- MakeMaker staticmake section:

# --- MakeMaker makeaperl section ---
MAP_TARGET    = perl
FULLPERL      = C:\devel\Shortcake\sandbox\perl\bin\perl.exe

$(MAP_TARGET) :: static $(MAKE_APERL_FILE)
	$(MAKE) $(USEMAKEFILE) $(MAKE_APERL_FILE) $@

$(MAKE_APERL_FILE) : $(FIRST_MAKEFILE) pm_to_blib
	$(NOECHO) $(ECHO) Writing \"$(MAKE_APERL_FILE)\" for this $(MAP_TARGET)
	$(NOECHO) $(PERLRUNINST) \
		Makefile.PL DIR= \
		MAKEFILE=$(MAKE_APERL_FILE) LINKTYPE=static \
		MAKEAPERL=1 NORECURS=1 CCCDLFLAGS=


# --- MakeMaker test section:

TEST_VERBOSE=0
TEST_TYPE=test_$(LINKTYPE)
TEST_FILE = test.pl
TEST_FILES = t/*.t
TESTDB_SW = -d

testdb :: testdb_$(LINKTYPE)

test :: $(TEST_TYPE) subdirs-test

subdirs-test ::
	$(NOECHO) $(NOOP)


test_dynamic :: pure_all
	$(FULLPERLRUN) "-MExtUtils::Command::MM" "-e" "test_harness($(TEST_VERBOSE), '$(INST_LIB)', '$(INST_ARCHLIB)')" $(TEST_FILES)

testdb_dynamic :: pure_all
	$(FULLPERLRUN) $(TESTDB_SW) "-I$(INST_LIB)" "-I$(INST_ARCHLIB)" $(TEST_FILE)

test_ : test_dynamic

test_static :: pure_all $(MAP_TARGET)
	./$(MAP_TARGET) "-MExtUtils::Command::MM" "-e" "test_harness($(TEST_VERBOSE), '$(INST_LIB)', '$(INST_ARCHLIB)')" $(TEST_FILES)

testdb_static :: pure_all $(MAP_TARGET)
	./$(MAP_TARGET) $(TESTDB_SW) "-I$(INST_LIB)" "-I$(INST_ARCHLIB)" $(TEST_FILE)



# --- MakeMaker ppd section:
# Creates a PPD (Perl Package Description) for a binary distribution.
ppd :
	$(NOECHO) $(ECHO) "<SOFTPKG NAME=\"$(DISTNAME)\" VERSION=\"$(VERSION)\">" > $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "    <ABSTRACT>Perl wrappers for the GLib utility and Object libraries</ABSTRACT>" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "    <AUTHOR></AUTHOR>" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "    <IMPLEMENTATION>" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "        <REQUIRE NAME=\"ExtUtils::Depends\" VERSION=\"0.3\" />" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "        <REQUIRE NAME=\"ExtUtils::PkgConfig\" VERSION=\"1\" />" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "        <ARCHITECTURE NAME=\"MSWin32-x86-multi-thread-5.16\" />" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "        <CODEBASE HREF=\"\" />" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) "    </IMPLEMENTATION>" >> $(DISTNAME).ppd
	$(NOECHO) $(ECHO) ^</SOFTPKG^> >> $(DISTNAME).ppd


# --- MakeMaker pm_to_blib section:

pm_to_blib : $(FIRST_MAKEFILE) $(TO_INST_PM)
	$(NOECHO) $(ABSPERLRUN) -MExtUtils::Install -e "pm_to_blib({{@ARGV}}, '$(INST_LIB)\auto', q[$(PM_FILTER)], '$(PERM_DIR)')" -- \
	  build/IFiles.pm $(INST_ARCHLIB)/$(FULLEXT)/Install/Files.pm \
	  lib/Glib/GenPod.pm $(INST_LIBDIR)/Glib/GenPod.pm \
	  lib/Glib.pm $(INST_LIBDIR)/Glib.pm \
	  gperl.h $(INST_ARCHLIB)/$(FULLEXT)/Install/gperl.h \
	  lib/Glib/Object/Subclass.pm $(INST_LIBDIR)/Glib/Object/Subclass.pm \
	  devel.pod $(INST_LIBDIR)/Glib/devel.pod \
	  gperl_marshal.h $(INST_ARCHLIB)/$(FULLEXT)/Install/gperl_marshal.h \
	  lib/Glib/ParseXSDoc.pm $(INST_LIBDIR)/Glib/ParseXSDoc.pm \
	  lib/Glib/MakeHelper.pm $(INST_LIBDIR)/Glib/MakeHelper.pm \
	  lib/Glib/CodeGen.pm $(INST_LIBDIR)/Glib/CodeGen.pm \
	  doctypes $(INST_ARCHLIB)/$(FULLEXT)/Install/doctypes \
	  C:\devel\Shortcake\sources\003-gtk2-perl-bindings\Glib-1.280\typemap $(INST_ARCHLIB)/$(FULLEXT)/Install/typemap 
	$(NOECHO) $(TOUCH) pm_to_blib


# --- MakeMaker selfdocument section:


# --- MakeMaker postamble section:

# these are special for Glib since it's providing the modules,
# it just has to make sure that they are ready before it can go
build/doc.pl :: $(INST_LIB)/Glib/ParseXSDoc.pm

build/podindex :: $(INST_LIB)/Glib/GenPod.pm

$(INST_LIB)/$(FULLEXT)/xsapi.pod :: build/doc.pl apidoc.pl xsapi.pod.head xsapi.pod.foot
	$(NOECHO) $(ECHO) Creating XS API documentation...
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe apidoc.pl xsapi.pod.head xsapi.pod.foot build/doc.pl > $@


gperl.h.gch: gperl.h
	$(CCCMD) $(CCCDLFLAGS) "-I$(PERL_INC)" $(PASTHRU_DEFINE) $(DEFINE) gperl.h

precompiled-headers: gperl.h.gch

realclean ::
	-$(RM_RF) build perl-$(DISTNAME).spec gperl.h.gch 

BLIB_DONE=build/blib_done_$(LINKTYPE)

build/blib_done_dynamic :: $(INST_DYNAMIC)
	$(NOECHO) $(TOUCH) $@

build/blib_done_static :: $(INST_STATIC)
	$(NOECHO) $(TOUCH) $@

build/blib_done_ :: build/blib_done_dynamic
	$(NOECHO) $(TOUCH) $@

# documentation stuff
$(INST_LIB)/Glib/GenPod.pm $(INST_LIB)/Glib/ParseXSDoc.pm: pm_to_blib

build/doc.pl :: Makefile Glib.xs GError.xs GUtils.xs GLog.xs GType.xs GBoxed.xs GObject.xs GValue.xs GClosure.xs GSignal.xs GMainLoop.xs GIOChannel.xs GParamSpec.xs GKeyFile.xs GOption.xs GBookmarkFile.xs
	$(NOECHO) $(ECHO) Parsing XS files...
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe -I $(INST_LIB) -I $(INST_ARCHLIB) -MGlib::ParseXSDoc \
		-e "xsdocparse (qw(Glib.xs GError.xs GUtils.xs GLog.xs GType.xs GBoxed.xs GObject.xs GValue.xs GClosure.xs GSignal.xs GMainLoop.xs GIOChannel.xs GParamSpec.xs GKeyFile.xs GOption.xs GBookmarkFile.xs))" > $@

# passing all of these files through the single podindex file, which is 
# created at the same time, prevents problems with -j4 where xsdoc2pod would 
# have multiple instances
$(INST_LIB)\Glib\Utils.pod $(INST_LIB)\Glib\OptionGroup.pod $(INST_LIB)\Glib\Object.pod $(INST_LIB)\Glib\Param\UInt64.pod $(INST_LIB)\Glib\Type.pod $(INST_LIB)\Glib\BookmarkFile.pod $(INST_LIB)\Glib\Param\Enum.pod $(INST_LIB)\Glib\Signal.pod $(INST_LIB)\Glib\Error.pod $(INST_LIB)\Glib\OptionContext.pod $(INST_LIB)\Glib\KeyFile.pod $(INST_LIB)\Glib\Param\Int64.pod $(INST_LIB)\Glib\Flags.pod $(INST_LIB)\Glib\version.pod $(INST_LIB)\Glib\Param\Double.pod $(INST_LIB)\Glib\Markup.pod $(INST_LIB)\Glib\Param\Int.pod $(INST_LIB)\Glib\Param\UInt.pod $(INST_LIB)\Glib\Param\GType.pod $(INST_LIB)\Glib\ParamSpec.pod $(INST_LIB)\Glib\MainLoop.pod $(INST_LIB)\Glib\Param\Flags.pod $(INST_LIB)\Glib\Log.pod $(INST_LIB)\Glib\Boxed.pod :: build/podindex

build/podindex :: $(BLIB_DONE) Makefile build/doc.pl $(POD_DEPENDS)
	$(NOECHO) $(ECHO) Generating POD...
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe -I $(INST_LIB) -I $(INST_ARCHLIB) -MGlib::GenPod -M$(NAME) \
		-e "add_types (qq(doctypes));  Glib::GenPod::set_copyright(qq/Copyright (C) 2003-2011 by the gtk2-perl team.\n\nThis software is licensed under the LGPL.  See L<Glib> for a full notice.\n/); Glib::GenPod::set_main_mod(qq(Glib)); $(POD_SET) xsdoc2pod(q(build/doc.pl), q($(INST_LIB)), q(build/podindex));"

$(INST_LIB)/$(FULLEXT)/:
	C:\devel\Shortcake\sandbox\perl\bin\perl.exe -MExtUtils::Command -e mkpath $@

$(INST_LIB)/$(FULLEXT)/index.pod :: $(INST_LIB)/$(FULLEXT)/ build/podindex
	$(NOECHO) $(ECHO) Creating POD index...
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe -e "print qq(\n=head1 NAME\n\n$(NAME) - API Reference Pod Index\n\n=head1 PAGES\n\n=over\n\n)" \
		> $(INST_LIB)/$(FULLEXT)/index.pod
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe -ne "print q(=item L<) . (split q( ))[1] . qq(>\n\n);" < build/podindex >> $(INST_LIB)/$(FULLEXT)/index.pod
	$(NOECHO) C:\devel\Shortcake\sandbox\perl\bin\perl.exe -e "print qq(=back\n\n);" >> $(INST_LIB)/$(FULLEXT)/index.pod


# End.
