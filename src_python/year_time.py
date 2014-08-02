import sys, string
import datetime

class TimeByDay:
  def __init__(self, mounth):
    mounth_index = {'enero': 1, 'febrero':3, 'marzo':5, 'abril':7, 'mayo':9, 'junio':11, 'julio':13, 'agosto':15, 'septiembre':17, 'octubre':19, 'noviembre':21, 'diciembre':23}

    applied_index = mounth_index[mounth]

    self.time_by_day = {'01':[0,0], '02':[0,0], '03':[0,0], '04':[0,0], '05':[0,0], '06':[0,0], '07':[0,0], '08':[0,0], '09':[0,0], '10':[0,0], '11':[0,0], '12':[0,0], '13':[0,0], '14':[0,0], '15':[0,0], '16':[0,0], '17':[0,0], '18':[0,0], '19':[0,0], '20':[0,0], '21':[0,0], '22':[0,0], '23':[0,0], '24':[0,0], '25':[0,0], '26':[0,0], '27':[0,0], '28':[0,0], '29':[0,0], '30':[0,0], '31':[0,0]}

    f = open("year_time.txt")  

    offset = 1

    for line in f.readlines():
       words = str.split(line)

       if len(words) > 0:
         day = words[0]
         
         [modified_hour, modified_min] = self.modify_opened_hour(int(words[applied_index][0:2]), int(words[applied_index][3:5]))
#hora_apertura = str('%02d' % (int(words[applied_index][0:2])+offset))
#         min_apertura = str('%02d' % (int(words[applied_index][3:5])))
         hora_apertura = str('%02d' % modified_hour)
         min_apertura = str('%02d' % modified_min)
         hora_cierre = str('%02d' % (int(words[applied_index+1][0:2])))
         min_cierre = str('%02d' % (int(words[applied_index+1][3:5])))

         self.time_by_day[day] = [hora_apertura+':'+min_apertura, hora_cierre+':'+min_cierre] 
         
    print self.time_by_day['26']

    f.close()  

  def get_time_by_day(self):
     return self.time_by_day;

  def is_time_to_open(self, day, time):
     ret = False
     if self.time_by_day[day][0] == time:
        ret = True

     return ret

  def is_time_to_close(self, day, time):
     ret = False
     if self.time_by_day[day][1] == time:
        ret = True
     return ret

  def modify_opened_hour(self, hour, minutes):
     offset_min = 30

     if minutes < 30:
       new_hour = hour
       new_minutes = minutes + offset_min
     else:
       new_hour = hour + 1;
       new_minutes = minutes - 30

     ret = [new_hour, new_minutes]
     return ret

if __name__== "__main__":
    enero = TimeByDay('enero')
    print enero.time_by_day

    print enero.is_time_to_close('31', '17:29')

