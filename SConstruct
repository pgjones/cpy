#-*-python-*-
# Main build script for Avaons

############### You should not need to edit below this line ############
import os

# Get build environment
env = Environment(ENV = os.environ)

# Temp always in debug
env.Append(CXXFLAGS=["-g"])
env.Append(LINKFLAGS=["-g"])

ldflags = env.backtick( "python-config --includes").split() # Split on space, diff flags
ldflags.extend(env.backtick( "python-config --libs").split())
ldflags.extend(env.backtick( "python-config --ldflags").split())
# Put all options after -u in LINKFLAGS, may not have a -u part though
try:
    idx = ldflags.index('-u')
    env.Append(LINKFLAGS=ldflags[idx:])
    del ldflags[idx:] # Remove the -u part
except ValueError:
    idx = -1
env.MergeFlags(' '.join(ldflags))

# Creates binary file
env.Program(target = 'cpy', source = [ "cpy.cc" ])
