#############################################################################
# Makefile for building: libXCP.so.1.0.0
# Template: lib
# Command: make
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       =
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       =
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = XCPLib1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -shared -Wl,-soname,libXCP.so.1
LIBS          = $(SUBLIBS) -lGL -lpthread
AR            = ar cqs
RANLIB        =
SED           = sed

# define strip tool
ifeq ($(CXX),arm-linux-g++)
	STRIP = arm-linux-strip
else
	STRIP = strip
endif

####### Output directory

OBJECTS_DIR   = debug/

####### Files

SOURCES       = CANMessage.cpp \
		CANMessageFactory.cpp \
		ConnectPacket.cpp \
		ConnectPositivePacket.cpp \
		DAQPackets.cpp \
		DisconnectPacket.cpp \
		DTO.cpp \
		ErrorAccessLockedPacket.cpp \
		ErrorAccessDeniedPacket.cpp \
		ErrorCommandUnknown.cpp \
		ErrorMemoryOverflowPacket.cpp \
		ErrorOutOfRangePacket.cpp \
		ErrorSequencePacket.cpp \
		GetSeedPacket.cpp \
		GetStatusPacket.cpp \
		IncomingMessageHandler.cpp \
		IXCPMessage.cpp \
		IXCPPacket.cpp \
		PacketFactory.cpp \
		SetMTAPacket.cpp \
		SlaveMemory.cpp \
		SynchPacket.cpp \
		TCPHeader.cpp \
		TCPMessage.cpp \
		TCPMessageFactory.cpp \
		UnlockPacket.cpp \
		UploadPacket.cpp \
		DownloadPacket.cpp \
		Utils.cpp \
		XCPMaster.cpp
OBJECTS       = debug/CANMessage.o \
		debug/CANMessageFactory.o \
		debug/ConnectPacket.o \
		debug/ConnectPositivePacket.o \
		debug/DAQPackets.o \
		debug/DisconnectPacket.o \
		debug/DTO.o \
		debug/ErrorAccessLockedPacket.o \
		debug/ErrorAccessDeniedPacket.o \
		debug/ErrorCommandUnknown.o \
		debug/ErrorMemoryOverflowPacket.o \
		debug/ErrorOutOfRangePacket.o \
		debug/ErrorSequencePacket.o \
		debug/GetSeedPacket.o \
		debug/GetStatusPacket.o \
		debug/IncomingMessageHandler.o \
		debug/IXCPMessage.o \
		debug/IXCPPacket.o \
		debug/PacketFactory.o \
		debug/SetMTAPacket.o \
		debug/SlaveMemory.o \
		debug/SynchPacket.o \
		debug/TCPHeader.o \
		debug/TCPMessage.o \
		debug/TCPMessageFactory.o \
		debug/UnlockPacket.o \
		debug/UploadPacket.o \
		debug/DownloadPacket.o \
		debug/Utils.o \
		debug/XCPMaster.o
DIST          = CANMessageFactory.h \
		CANMessage.h \
		CommandPacket.h \
		ConnectPacket.h \
		ConnectPositivePacket.h \
		DAQPackets.h \
		DisconnectPacket.h \
		DTO.h \
		ErrorAccessLockedPacket.h \
		ErrorAccessDeniedPacket.h \
		ErrorCommandUnknown.h \
		ErrorMemoryOverflowPacket.h \
		ErrorOutOfRangePacket.h \
		ErrorPacket.h \
		ErrorSequencePacket.h \
		GetSeedPacket.h \
		GetStatusPacket.h \
		ICTO.h \
		IIncomingMessageHandler.h \
		IMessageFactory.h \
		IncomingMessageHandler.h \
		IXCPHeader.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IXCPTail.h \
		PacketFactory.h \
		ResponsePacket.h \
		SetMTAPacket.h \
		SlaveMemory.h \
		SynchPacket.h \
		TCPHeader.h \
		TCPMessageFactory.h \
		TCPMessage.h \
		UnlockPacket.h \
		UploadPacket.h \
		DownloadPacket.h \
		Utils.h \
		XCPMaster.h \
		XCPApiDecl.h CANMessage.cpp \
		CANMessageFactory.cpp \
		ConnectPacket.cpp \
		ConnectPositivePacket.cpp \
		DAQPackets.cpp \
		DisconnectPacket.cpp \
		DTO.cpp \
		ErrorAccessLockedPacket.cpp \
		ErrorAccessDeniedPacket.cpp \
		ErrorCommandUnknown.cpp \
		ErrorMemoryOverflowPacket.cpp \
		ErrorOutOfRangePacket.cpp \
		ErrorSequencePacket.cpp \
		GetSeedPacket.cpp \
		GetStatusPacket.cpp \
		IncomingMessageHandler.cpp \
		IXCPMessage.cpp \
		IXCPPacket.cpp \
		PacketFactory.cpp \
		SetMTAPacket.cpp \
		SlaveMemory.cpp \
		SynchPacket.cpp \
		TCPHeader.cpp \
		TCPMessage.cpp \
		TCPMessageFactory.cpp \
		UnlockPacket.cpp \
		UploadPacket.cpp \
		DownloadPacket.cpp \
		Utils.cpp \
		XCPMaster.cpp
QMAKE_TARGET  = XCPLib
DESTDIR       = ../build/Debug/
TARGET        = libXCP.so.1.0.0
TARGETA       = ../build/Debug/libXCP.a
TARGET0       = libXCP.so
TARGETD       = libXCP.so.1.0.0
TARGET1       = libXCP.so.1
TARGET2       = libXCP.so.1.0


first: all
####### Build rules

../build/Debug/$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)
	@test -d ../build/Debug/ || mkdir -p ../build/Debug/
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) ../build/Debug/$(TARGET)
	-$(MOVE) $(TARGET)  ../build/Debug/
	-$(DEL_FILE) ../build/Debug/$(TARGET0)
	-$(DEL_FILE) ../build/Debug/$(TARGET1)
	-$(DEL_FILE) ../build/Debug/$(TARGET2)
	-$(MOVE) $(TARGET0) ../build/Debug/
	-$(MOVE) $(TARGET1) ../build/Debug/
	-$(MOVE) $(TARGET2) ../build/Debug/



staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP)
	-$(DEL_FILE) $(TARGETA)
	$(AR) $(TARGETA) $(OBJECTS)

all: ../build/Debug/$(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents CANMessageFactory.h CANMessage.h CommandPacket.h ConnectPacket.h ConnectPositivePacket.h DAQPackets.h DisconnectPacket.h DTO.h ErrorAccessLockedPacket.h ErrorAccessDeniedPacket.h ErrorCommandUnknown.h ErrorMemoryOverflowPacket.h ErrorOutOfRangePacket.h ErrorPacket.h ErrorSequencePacket.h GetSeedPacket.h GetStatusPacket.h ICTO.h IIncomingMessageHandler.h IMessageFactory.h IncomingMessageHandler.h IXCPHeader.h IXCPMessage.h IXCPPacket.h IXCPTail.h PacketFactory.h ResponsePacket.h SetMTAPacket.h SlaveMemory.h SynchPacket.h TCPHeader.h TCPMessageFactory.h TCPMessage.h UnlockPacket.h UploadPacket.h DownloadPacket.h Utils.h XCPMaster.h XCPApiDecl.h $(DISTDIR)/
	$(COPY_FILE) --parents CANMessage.cpp CANMessageFactory.cpp ConnectPacket.cpp ConnectPositivePacket.cpp DAQPackets.cpp DisconnectPacket.cpp DTO.cpp ErrorAccessLockedPacket.cpp ErrorAccessDeniedPacket.cpp ErrorCommandUnknown.cpp ErrorMemoryOverflowPacket.cpp ErrorOutOfRangePacket.cpp ErrorSequencePacket.cpp GetSeedPacket.cpp GetStatusPacket.cpp IncomingMessageHandler.cpp IXCPMessage.cpp IXCPPacket.cpp PacketFactory.cpp SetMTAPacket.cpp SlaveMemory.cpp SynchPacket.cpp TCPHeader.cpp TCPMessage.cpp TCPMessageFactory.cpp UnlockPacket.cpp UploadPacket.cpp DownloadPacket.cpp Utils.cpp XCPMaster.cpp $(DISTDIR)/


clean: compiler_clean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean
	-$(DEL_FILE) ../build/Debug/$(TARGET)
	-$(DEL_FILE) ../build/Debug/$(TARGET0) ../build/Debug/$(TARGET1) ../build/Debug/$(TARGET2) $(TARGETA)


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean

####### Compile

debug/CANMessage.o: CANMessage.cpp CANMessage.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/CANMessage.o CANMessage.cpp

debug/CANMessageFactory.o: CANMessageFactory.cpp CANMessageFactory.h \
		IMessageFactory.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h \
		CANMessage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/CANMessageFactory.o CANMessageFactory.cpp

debug/ConnectPacket.o: ConnectPacket.cpp ConnectPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ConnectPacket.o ConnectPacket.cpp

debug/ConnectPositivePacket.o: ConnectPositivePacket.cpp ConnectPositivePacket.h \
		ResponsePacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ConnectPositivePacket.o ConnectPositivePacket.cpp

debug/DAQPackets.o: DAQPackets.cpp DAQPackets.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/DAQPackets.o DAQPackets.cpp

debug/DisconnectPacket.o: DisconnectPacket.cpp DisconnectPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/DisconnectPacket.o DisconnectPacket.cpp

debug/DTO.o: DTO.cpp DTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		SlaveMemory.h \
		DAQPackets.h \
		CommandPacket.h \
		ICTO.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/DTO.o DTO.cpp

debug/ErrorAccessLockedPacket.o: ErrorAccessLockedPacket.cpp ErrorAccessLockedPacket.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorAccessLockedPacket.o ErrorAccessLockedPacket.cpp

debug/ErrorAccessDeniedPacket.o: ErrorAccessDeniedPacket.cpp ErrorAccessDeniedPacket.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorAccessDeniedPacket.o ErrorAccessDeniedPacket.cpp

debug/ErrorCommandUnknown.o: ErrorCommandUnknown.cpp ErrorCommandUnknown.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorCommandUnknown.o ErrorCommandUnknown.cpp

debug/ErrorMemoryOverflowPacket.o: ErrorMemoryOverflowPacket.cpp ErrorMemoryOverflowPacket.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorMemoryOverflowPacket.o ErrorMemoryOverflowPacket.cpp

debug/ErrorOutOfRangePacket.o: ErrorOutOfRangePacket.cpp ErrorOutOfRangePacket.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorOutOfRangePacket.o ErrorOutOfRangePacket.cpp

debug/ErrorSequencePacket.o: ErrorSequencePacket.cpp ErrorSequencePacket.h \
		ErrorPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/ErrorSequencePacket.o ErrorSequencePacket.cpp

debug/GetSeedPacket.o: GetSeedPacket.cpp GetSeedPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/GetSeedPacket.o GetSeedPacket.cpp

debug/GetStatusPacket.o: GetStatusPacket.cpp GetStatusPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/GetStatusPacket.o GetStatusPacket.cpp

debug/IncomingMessageHandler.o: IncomingMessageHandler.cpp IncomingMessageHandler.h \
		IIncomingMessageHandler.h \
		ConnectPositivePacket.h \
		ResponsePacket.h \
		ICTO.h \
		IXCPPacket.h \
		XCPApiDecl.h \
		XCPMaster.h \
		IMessageFactory.h \
		IXCPMessage.h \
		IXCPHeader.h \
		IXCPTail.h \
		ConnectPacket.h \
		CommandPacket.h \
		DisconnectPacket.h \
		PacketFactory.h \
		DAQPackets.h \
		GetSeedPacket.h \
		SlaveMemory.h \
		TCPMessage.h \
		GetStatusPacket.h \
		UploadPacket.h \
		DownloadPacket.h \
		ErrorAccessLockedPacket.h \
		ErrorAccessDeniedPacket.h \
		ErrorPacket.h \
		ErrorOutOfRangePacket.h \
		ErrorSequencePacket.h \
		ErrorMemoryOverflowPacket.h \
		UnlockPacket.h \
		DTO.h \
		ErrorCommandUnknown.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/IncomingMessageHandler.o IncomingMessageHandler.cpp

debug/IXCPMessage.o: IXCPMessage.cpp IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/IXCPMessage.o IXCPMessage.cpp

debug/IXCPPacket.o: IXCPPacket.cpp IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/IXCPPacket.o IXCPPacket.cpp

debug/PacketFactory.o: PacketFactory.cpp PacketFactory.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		CommandPacket.h \
		ICTO.h \
		ConnectPacket.h \
		DAQPackets.h \
		ResponsePacket.h \
		GetSeedPacket.h \
		SlaveMemory.h \
		ConnectPositivePacket.h \
		GetStatusPacket.h \
		SynchPacket.h \
		ErrorPacket.h \
		DisconnectPacket.h \
		SetMTAPacket.h \
		UploadPacket.h \
		DownloadPacket.h \
		ErrorAccessLockedPacket.h \
		ErrorAccessDeniedPacket.h \
		ErrorOutOfRangePacket.h \
		ErrorSequencePacket.h \
		ErrorMemoryOverflowPacket.h \
		XCPMaster.h \
		IMessageFactory.h \
		IXCPMessage.h \
		IXCPHeader.h \
		IXCPTail.h \
		TCPMessage.h \
		UnlockPacket.h \
		DTO.h \
		ErrorCommandUnknown.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/PacketFactory.o PacketFactory.cpp

debug/SetMTAPacket.o: SetMTAPacket.cpp SetMTAPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/SetMTAPacket.o SetMTAPacket.cpp

debug/SlaveMemory.o: SlaveMemory.cpp SlaveMemory.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/SlaveMemory.o SlaveMemory.cpp

debug/SynchPacket.o: SynchPacket.cpp SynchPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ErrorPacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/SynchPacket.o SynchPacket.cpp

debug/TCPHeader.o: TCPHeader.cpp TCPHeader.h \
		IXCPHeader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/TCPHeader.o TCPHeader.cpp

debug/TCPMessage.o: TCPMessage.cpp TCPMessage.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h \
		TCPHeader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/TCPMessage.o TCPMessage.cpp

debug/TCPMessageFactory.o: TCPMessageFactory.cpp TCPMessageFactory.h \
		IMessageFactory.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h \
		TCPMessage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/TCPMessageFactory.o TCPMessageFactory.cpp

debug/UnlockPacket.o: UnlockPacket.cpp UnlockPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/UnlockPacket.o UnlockPacket.cpp

debug/UploadPacket.o: UploadPacket.cpp UploadPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/UploadPacket.o UploadPacket.cpp

debug/DownloadPacket.o: DownloadPacket.cpp DownloadPacket.h \
		CommandPacket.h \
		ICTO.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		ResponsePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/DownloadPacket.o DownloadPacket.cpp

debug/Utils.o: Utils.cpp Utils.h \
		XCPApiDecl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/Utils.o Utils.cpp

debug/XCPMaster.o: XCPMaster.cpp XCPMaster.h \
		IMessageFactory.h \
		IXCPMessage.h \
		IXCPPacket.h \
		IIncomingMessageHandler.h \
		XCPApiDecl.h \
		IXCPHeader.h \
		IXCPTail.h \
		ConnectPacket.h \
		CommandPacket.h \
		ICTO.h \
		DisconnectPacket.h \
		PacketFactory.h \
		DAQPackets.h \
		ResponsePacket.h \
		GetSeedPacket.h \
		SlaveMemory.h \
		TCPMessage.h \
		TCPMessageFactory.h \
		CANMessageFactory.h \
		IncomingMessageHandler.h \
		ConnectPositivePacket.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debug/XCPMaster.o XCPMaster.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:
