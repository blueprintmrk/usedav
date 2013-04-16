#!/bin/sh

# This file is part of fusedav.
#
# fusedav is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# fusedav is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with fusedav; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

set -e
autoreconf --force --install --symlink

if [ "x$1" = "xc" ]; then
        ./configure CFLAGS='-g -O0' $args
        make clean
else
        echo
        echo "----------------------------------------------------------------"
        echo "Initialized build system. For a common configuration please run:"
        echo "----------------------------------------------------------------"
        echo
        echo "./configure CFLAGS='-g -O0' $args"
        echo
fi