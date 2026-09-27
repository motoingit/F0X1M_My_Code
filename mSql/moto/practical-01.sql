-- flow of creation

-- HOSPITAL
--    ↓
-- DEPARTMENT
--    ↓
-- DOCTOR
--    ↓
-- PATIENT
--    ↓
-- APPOINTMENT





-- HOSPITAL table
CREATE TABLE hospital (
    id           NUMBER PRIMARY KEY,
    name         VARCHAR2(50),
    address      VARCHAR2(100),
    phone_number NUMBER
);

-- DEPARTMENT table
CREATE TABLE department (
    id          NUMBER PRIMARY KEY,
    name        VARCHAR2(50),
    location    VARCHAR2(100),
    hospital_id NUMBER,

    FOREIGN KEY (hospital_id)
      REFERENCES hospital(id)
);

-- DOCTOR table
CREATE TABLE doctor (
    id             NUMBER PRIMARY KEY,
    name           VARCHAR2(50),
    specialization VARCHAR2(20),
    phone_number   NUMBER,
    department_id  NUMBER,

    FOREIGN KEY (department_id)
      REFERENCES department(id)
);

-- APPOINTMENT table
CREATE TABLE appointment (
    id         NUMBER PRIMARY KEY,
    date       DATE,
    time       TIMESTAMP,
    status     VARCHAR2(10),
    doctor_id  NUMBER,
    patient_id NUMBER,

    FOREIGN KEY (doctor_id)
        REFERENCES doctor(id),

    FOREIGN KEY (patient_id)
        REFERENCES patient(id)
);

-- PATIENT table
CREATE TABLE patient (
    id           NUMBER PRIMARY KEY,
    name         VARCHAR2(50),
    dob          DATE,
    gender       VARCHAR2(10),
    address      VARCHAR2(50),
    phone_number NUMBER,
    blood_group  VARCHAR2(10)
);

-- BILL table
CREATE TABLE bill (
    id                   NUMBER PRIMARY KEY,
    total_amount         NUMBER,
    date_of_bill_generation DATE,
    payment_status       VARCHAR2(10),
    patient_id           NUMBER,

    FOREIGN KEY (patient_id)
        REFERENCES patient(id)
);

-- ADMISSION table
CREATE TABLE admission (
    id             NUMBER PRIMARY KEY,
    admit_date     DATE,
    discharge_date DATE,
    patient_id     NUMBER,
    room_id        NUMBER,

    FOREIGN KEY (patient_id)
        REFERENCES patient(id)
);

-- MEDICAL_RECORD table
CREATE TABLE medical_record (
    id          NUMBER PRIMARY KEY,
    diagnosis   VARCHAR2(200),
    treatment   VARCHAR2(200),
    visit_date  DATE,
    patient_id  NUMBER,
    doctor_id   NUMBER,

    FOREIGN KEY (patient_id)
        REFERENCES patient(id),

    FOREIGN KEY (doctor_id)
        REFERENCES doctor(id)
);

--
INSERT INTO hospital VALUES (101, 'Navratan Hospital', 'Dehradun/nakronda', 2323);

--
INSERT INTO department VALUES (101, 'darma', 'block-4', 100);
INSERT INTO department VALUES (102, 'ortho', 'block-1', 100);

--
INSERT INTO doctor VALUES (101, 'mohit', 'datmatologist', 9123, 101);
INSERT INTO doctor VALUES (102, 'karma', 'orthologist', 9123, 102);

--
INSERT INTO patient VALUES (101, 'shisu', SYSDATE, 'male', 'Dehradun/nakronda', 9123,'a+');
INSERT INTO patient VALUES (102, 'xuisu', SYSDATE, 'female', 'Dehradun/nakronda', 91233,'a+');
