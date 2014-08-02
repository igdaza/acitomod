import urllib2  
import sys, string

  
try:  
#f = urllib2.urlopen("http://www.python.org")  
    days = {'1':[0,0], '2':[0,0], '3':[0,0], '4':[0,0], '5':[0,0], '6':[0,0], '7':[0,0], '8':[0,0], '9':[0,0], '10':[0,0], '11':[0,0], '12':[0,0], '13':[0,0], '14':[0,0], '15':[0,0], '16':[0,0], '17':[0,0], '18':[0,0], '19':[0,0], '20':[0,0], '21':[0,0], '22':[0,0], '23':[0,0], '24':[0,0], '25':[0,0], '26':[0,0], '27':[0,0], '28':[0,0], '29':[0,0], '30':[0,0], '31':[0,0]}

    mounths = {'enero': days,
               'febrero': days}

    year = "2013"
    f = urllib2.urlopen("http://www.fomento.gob.es/salidapuestasol/"+year+"/Guadalajara-"+year+".txt")  

#print f.read()
    index = 1
    for line in f.readlines()[7:38]:
      print line+'\n'
      words = str.split(line)
      if len(words) == 25:
        days[str(index)] = words[1]
        index = index + 1
#print days

      
    f.close()  

except HTTPError, e:  
    print "Error"  
#    print e.code  
except URLError, e:  
    print "Error"  
#    print e.reason  


