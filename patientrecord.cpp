#ifndef CLINIC_MODEL_H 
#define CLINIC_MODEL_H 
#include <iostream> 
#include <string> 
#include <vector> 
namespace ClinicModel { 
// 1. Appointable Interface Class 
class Appointable { 
public: 
virtual ~Appointable() = default; 
}; 
// 2. Appointment Class 
class Appointment { 
private: 
std::string appointmentID; 
std::string date; 
std::string time; 
public: 
Appointment(std::string id, std::string d, std::string t) 
: appointmentID(id), date(d), time(t) {} 
 
        std::string getAppointmentID() const { return appointmentID; } 
        std::string getDate() const { return date; } 
        std::string getTime() const { return time; } 
 
        void displayAppointment() const { 
            std::cout << "Appointment ID: " << appointmentID  
                      << ", Date: " << date  
                      << ", Time: " << time << std::endl; 
        } 
    }; 
 
    // 3. PatientRecord Base Class 
    class PatientRecord : public Appointable { 
    protected: 
        std::string patientID; 
        std::string name; 
        int age; 
        std::string contactInfo; 
        std::vector<Appointment> appointments; 
 
    public: 
        PatientRecord(std::string id, std::string n, int a, std::string contact) 
            : patientID(id), name(n), age(a), contactInfo(contact) {} 
 
        virtual ~PatientRecord() {} 
 
        std::string getPatientID() const { return patientID; } 
        std::string getName() const { return name; } 
        int getAge() const { return age; } 
        std::string getContactInfo() const { return contactInfo; } 
 
        void addAppointment(const Appointment& appt) { 
            appointments.push_back(appt); 
        } 
 
        virtual std::string getPatientCategory() const = 0; 
        virtual void displayDetails() const = 0; 
    }; 
 
} // namespace ClinicModel 
 
// 4. Demonstration Main function to test execution 
int main() { 
    using namespace ClinicModel; 
 
    // Example concrete implementation for testing compilation and execution 
    class OutpatientRecord : public PatientRecord { 
    public: 
        OutpatientRecord(std::string id, std::string n, int a, std::string contact) 
            : PatientRecord(id, n, a, contact) {} 
 
        std::string getPatientCategory() const override { 
            return "Outpatient"; 
        } 
 
        void displayDetails() const override { 
            std::cout << "--- Patient Record ---" << std::endl; 
            std::cout << "ID: " << patientID << std::endl; 
            std::cout << "Name: " << name << std::endl; 
            std::cout << "Age: " << age << std::endl; 
            std::cout << "Category: " << getPatientCategory() << std::endl; 
            std::cout << "Contact: " << contactInfo << std::endl; 
            std::cout << "Total Appointments: " << appointments.size() << std::endl; 
        } 
    }; 
 
    OutpatientRecord patient("P001", "John Doe", 30, "555-0199"); 
    patient.addAppointment(Appointment("A101", "2026-11-10", "10:00 AM")); 
     
    patient.displayDetails(); 
 
    return 0; 
} 
 
#endif
