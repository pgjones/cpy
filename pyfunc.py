#!/usr/bin/env python

def funct(a=[]):
    a.append("a")
    a.extend(["a", "b"])
    return a
