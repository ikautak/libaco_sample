StaticLibrary('aco', ['libaco/aco.c', 'libaco/acosw.S'])

env = Environment(CCFLAGS='-std=c++17 -Wall -O3')
env.Program('main.cc', LIBS=['aco'], LIBPATH=['.'])

