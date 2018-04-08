# coding: utf-8
"""
Cubic UFO
https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cc

Aが√2未満ならば、Z軸中心に回転して二分探索で適切な角度を探す。
Aが√2以上ならば、まずはZ軸中心に45°回転して、その後Y軸を中心に回す。
Largeは不正解。
Y軸中心ではなく、X軸中心に回さないといけなかった？
"""

from math import *

def roty(v, a):
  return (
    v[0]*cos(a)+v[2]*sin(a),
    v[1],
    -v[0]*sin(a)+v[2]*cos(a))

def rotz(v, a):
  return (
    v[0]*cos(a)-v[1]*sin(a),
    v[0]*sin(a)+v[1]*cos(a),
    v[2])

T = input()
for t in range(T):
  A = input()
  print "Case #%d:" % (t+1)
  if A<sqrt(2):
    l,r = 0.,pi/4
    for _ in range(100):
      m = (l+r)/2
      a = sqrt(2)*cos(pi/4-m)
      if a<A:
        l = m
      else:
        r = m
    print "%.10f %.10f %.10f" % rotz((0.5, 0., 0.), l)
    print "%.10f %.10f %.10f" % rotz((0., 0.5, 0.), l)
    print "%.10f %.10f %.10f" % rotz((0., 0., 0.5), l)
  else:
    l,r = 0.,atan2(1,sqrt(2))
    for _ in range(100):
      m = (l+r)/2
      x1 = cos(m)*0.5
      x2 = cos(atan2(sqrt(2),1)-m)*hypot(sqrt(2),1)*0.5
      a = 2*sqrt(2)*x1 + sqrt(2)*(x2-x1)
      if a<A:
        l = m
      else:
        r = m
    print "%.10f %.10f %.10f" % roty(rotz((0.5, 0., 0.), pi/4), l)
    print "%.10f %.10f %.10f" % roty(rotz((0., 0.5, 0.), pi/4), l)
    print "%.10f %.10f %.10f" % roty(rotz((0., 0., 0.5), pi/4), l)
