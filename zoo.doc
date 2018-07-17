1.Provide 10 class names you would use in the model
1.ZooFacility
2.Zone
3.Habitat
4.Animal
5.Address

------------------------------------
2.Provide 5 most important entity classes and their class variables

public class ZooFacility {
	private String name;
	private Address address;
	private Collection zones;
}

public class Zone {
	private String name;
	private Collection habitats;
}

public class Habitat {
	private String name;
	private Integer totalCapacity;
	private Integer availableCapacity;
	private Collection availableAnimalType;
	private Collection availableAnimalNumber;
}

public class Animal {
	private String type;
	private Integer number;
}
public class Address {
	private String streetName;
	private String StreetPrefix;
	Private String PostalCode
}



------------------------------------
3.Provide 10 most important method signatures for Zoo Management system
Habitat findHabitatForAnimal(ZooFacility zoo, Animal animal)
Arraylist<Habitat> getHabitats(Zone zone)
Arraylist<Zone> getZones(ZooFacility zoo)
Integer getNumber(Animal animal)
Integer getType(Animal animal)
Zone findZoneForHabitat(ZooFacility zoo,  Animal animal)
Boolean isHabitatContainAnimal(Habitat habitat, Animal animal)
Boolean isAvailableAnimalType(Habitat habitat, string animalType))
Integer getAvailableAnimalNumber(Habitat habitat, Animal animal)
Integer getAvailableCapacity(Habitat habitat)


------------------------------------
4.Provide the code for the method:
Habitat findHabitatForAnimal(ZooFacility zoo, Animal animal){
	Arraylist<Zone> arrliZone = zoo.getZones();
	For(int i = 0; i < arrliZone.size(); i++){
		 Arraylist<Habitat> arrliHabitat  = arrliZone[i].getHabitats();
		For(int j = 0; j < arrliHabitat.size(); j++ ){
			if(arrliHabitat[j].isHabitatContainAnimal(arrliHabitat[j], animal)){
				if(arrliHabitat[j].getAvailableCapacity(arrliHabitat[j]) > animal.getNumber()){
					if(arrliHabitat[j].isAvailableAnimalType(arrliHabitat[j], animal.getType())){
						if(arrliHabitat[j].getAvailableAnimalNumber(arrliHabitat[j], animal) > animal.getNumber()){
							return arrliHabitat[j];	
						}
					}
				}
			}
		}
	}
}
	

--------------------------------------

I think to optimize this problem, we need to give new field that connect zone to animal such as species are differentiated in different zone, so that we dont need to search every zone.