Ass5: Democratic_Party.o Democratic_Politician.o Leader_Democretic.o Leader_republic.o Main.o Party.o PoliticalSys.o Politician.o Republican_Party.o Republican_politician.o social_democrat.o social_republic.o
	g++ Democratic_Party.o Democratic_Politician.o Leader_Democretic.o Leader_republic.o Main.o Party.o PoliticalSys.o Politician.o Republican_Party.o Republican_politician.o social_democrat.o social_republic.o -o Ass5

Democratic_Party.o: Democratic_Party.cpp Democratic_Party.h Party.h Politician.h
	g++ -c Democratic_Party.cpp

Democratic_Politician.o: Democratic_Politician.cpp Democratic_Politician.h Politician.h
	g++ -c Democratic_Politician.cpp

Leader_Democretic.o: Leader_Democretic.cpp Leader_Democretic.h Democratic_Politician.h Politician.h
	g++ -c Leader_Democretic.cpp 

Leader_republic.o: Leader_republic.cpp Leader_republic.h Republican_politician.h Politician.h
	g++ -c Leader_republic.cpp 

Main.o: Main.cpp PoliticalSys.h Politician.h Party.h
	g++ -c Main.cpp 

Party.o: Party.cpp Party.h Politician.h
	g++ -c Party.cpp

PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Politician.h Party.h Leader_Democretic.h Democratic_Politician.h social_denocrat.h Leader_republic.h Republican_politician.h social_republic.h Republican_Party.h Democratic_Party.h Exception.h
	g++ -c PoliticalSys.cpp 

Politician.o: Politician.cpp Politician.h
	g++ -c Politician.cpp 
Republican_Party.o: Republican_Party.cpp Republican_Party.h Party.h Politician.h
	g++ -c Republican_Party.cpp

Republican_politician.o: Republican_politician.cpp Republican_politician.h Politician.h
	g++ -c Republican_politician.cpp

social_democrat.o: social_democrat.cpp social_denocrat.h Democratic_Politician.h Politician.h
	g++ -c social_democrat.cpp 

social_republic.o: social_republic.cpp social_republic.h Republican_politician.h Politician.h
	g++ -c social_republic.cpp

clean:
	rm -rf *.o 

