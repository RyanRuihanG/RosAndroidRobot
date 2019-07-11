#!/usr/bin/env python
# coding=utf-8
import rospy
import json
import os.path
import re
import SocketServer
from std_msgs.msg import String

PinyinToneMark = {0: u"aoeiuv\u00fc",
                  1: u"\u0101\u014d\u0113\u012b\u016b\u01d6\u01d6",
                  2: u"\u00e1\u00f3\u00e9\u00ed\u00fa\u01d8\u01d8",
                  3: u"\u01ce\u01d2\u011b\u01d0\u01d4\u01da\u01da",
                  4: u"\u00e0\u00f2\u00e8\u00ec\u00f9\u01dc\u01dc"}


class Pinyin(object):
    data_path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                             'Mandarin.dat')

    def __init__(self, data_path=data_path):
        self.dict = {}
        for line in open(data_path):
            k, v = line.split('\t')
            self.dict[k] = v

    def decode_pinyin(self, s):
        s = s.lower()
        r = ""
        t = ""
        for c in s:
            if c >= 'a' and c <= 'z':
                t += c
            elif c == ':':
                assert t[-1] == 'u'
                t = t[:-1] + "\u00fc"
            else:
                if c >= '0' and c <= '5':
                    tone = int(c) % 5
                    if tone != 0:
                        m = re.search("[aoeiuv\u00fc]+", t)
                        if m is None:
                            t += c
                        elif len(m.group(0)) == 1:

                            t = t[:m.start(0)] \
                                + PinyinToneMark[tone][
                                    PinyinToneMark[0].index(m.group(0))] \
                                + t[m.end(0):]
                        else:
                            if 'a' in t:
                                t = t.replace("a", PinyinToneMark[tone][0])
                            elif 'o' in t:
                                t = t.replace("o", PinyinToneMark[tone][1])
                            elif 'e' in t:
                                t = t.replace("e", PinyinToneMark[tone][2])
                            elif t.endswith("ui"):
                                t = t.replace("i", PinyinToneMark[tone][3])
                            elif t.endswith("iu"):
                                t = t.replace("u", PinyinToneMark[tone][4])
                            else:
                                t += "!"
                r += t
                t = ""
        r += t
        return r

    def get_pinyin(self, chars=u'你好', splitter=u'-', show_tone_marks=False):
        result = []
        flag = 1
        for char in chars:
            key = "%X" % ord(char)
            try:
                result.append(self.decode_pinyin(
                    self.dict[key].split()[0].strip().lower())
                              if show_tone_marks
                              else self.dict[key].split()[0].strip()[:-1].lower())
                flag = 1
            except KeyError:
                if flag:
                    result.append(char)
                else:
                    result[-1] += char
                flag = 0

        return splitter.join(result)


def run():
    class MyHandler(SocketServer.BaseRequestHandler):
        def handle(self):
            while 1:
                dataReceived = self.request.recv(1024)
                if not dataReceived: break
                # self.request.send(dataReceived)
                if dataReceived != 'connected!':
                    data=json.loads(dataReceived)['content']['item'][0]
                    pubraw.publish(data)
                    pubpy.publish(p.get_pinyin(data))

    p = Pinyin()
    rospy.init_node('cspm_voice', anonymous=True)
    rate = rospy.Rate(10)  # 10hz
    pubpy = rospy.Publisher('voice_py', String, queue_size=10)
    pubraw = rospy.Publisher('voice_raw', String, queue_size=10)
    myServer = SocketServer.ThreadingTCPServer(('', 9400), MyHandler)
    myServer.serve_forever()
if __name__=='__main__':
    run()
