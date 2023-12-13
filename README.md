# CBNST-LAB
 
CREATE TABLE CUSTOMER (
    custno INT PRIMARY KEY,
    cname VARCHAR2(255),
    city VARCHAR2(255)
);

CREATE TABLE ORDER (
    orderno INT PRIMARY KEY,
    odate DATE,
    custno INT,
    ord_amt INT,
    FOREIGN KEY (custno) REFERENCES CUSTOMER(custno)
);

CREATE TABLE ORDER_ITEM (
    orderno INT,
    itemno INT,
    quantity INT,
    PRIMARY KEY (orderno, itemno),
    FOREIGN KEY (orderno) REFERENCES ORDER(orderno)
);

CREATE TABLE ITEM (
    itemno INT PRIMARY KEY,
    unitprice INT
);

CREATE TABLE SHIPMENT (
    orderno INT,
    warehouseno INT,
    ship_date DATE,
    PRIMARY KEY (orderno, warehouseno),
    FOREIGN KEY (orderno) REFERENCES ORDER(orderno)
);

CREATE TABLE WAREHOUSE (
    warehouseno INT PRIMARY KEY,
    city VARCHAR2(255)
);
CREATE SEQUENCE custno_seq START WITH 1 INCREMENT BY 1;


SELECT
    c.cname AS custname,
    COUNT(o.orderno) AS No_of_orders,
    AVG(o.ord_amt) AS Avg_order_amount
FROM
    CUSTOMER c
JOIN
    "ORDER" o ON c.custno = o.custno
GROUP BY
    c.cname;
SELECT DISTINCT
    o.orderno
FROM
    "ORDER" o
JOIN
    SHIPMENT s ON o.orderno = s.orderno
WHERE
    s.warehouseno IN (SELECT warehouseno FROM WAREHOUSE WHERE city = 'Dehradun')
AND
    NOT EXISTS (
        SELECT w.warehouseno
        FROM WAREHOUSE w
        WHERE w.city = 'Dehradun'
        MINUS
        SELECT s1.warehouseno
        FROM SHIPMENT s1
        WHERE s1.orderno = o.orderno
    );

CREATE VIEW customer_spending_view AS
SELECT
    c.cname AS customer_name,
    SUM(o.ord_amt) AS total_spending
FROM
    CUSTOMER c
JOIN
    "ORDER" o ON c.custno = o.custno
GROUP BY
    c.cname;

GRANT SELECT ON customer_spending_view TO PUBLIC;


-- Insert data into CUSTOMER table
INSERT INTO CUSTOMER VALUES (custno_seq.NEXTVAL, 'Customer1', 'City1');
INSERT INTO CUSTOMER VALUES (custno_seq.NEXTVAL, 'Customer2', 'City2');
INSERT INTO CUSTOMER VALUES (custno_seq.NEXTVAL, 'Customer3', 'City1');
INSERT INTO CUSTOMER VALUES (custno_seq.NEXTVAL, 'Customer4', 'City3');
INSERT INTO CUSTOMER VALUES (custno_seq.NEXTVAL, 'Customer5', 'City2');

-- Insert data into "ORDER" table
INSERT INTO "ORDER" VALUES (1, TO_DATE('2023-01-01', 'YYYY-MM-DD'), 1, 1000);
INSERT INTO "ORDER" VALUES (2, TO_DATE('2023-02-01', 'YYYY-MM-DD'), 2, 1500);
INSERT INTO "ORDER" VALUES (3, TO_DATE('2023-03-01', 'YYYY-MM-DD'), 3, 800);
INSERT INTO "ORDER" VALUES (4, TO_DATE('2023-04-01', 'YYYY-MM-DD'), 4, 1200);
INSERT INTO "ORDER" VALUES (5, TO_DATE('2023-05-01', 'YYYY-MM-DD'), 5, 2000);

-- Insert data into ORDER_ITEM table
INSERT INTO ORDER_ITEM VALUES (1, 1, 2);
INSERT INTO ORDER_ITEM VALUES (1, 2, 1);
INSERT INTO ORDER_ITEM VALUES (2, 1, 3);
INSERT INTO ORDER_ITEM VALUES (3, 1, 1);
INSERT INTO ORDER_ITEM VALUES (4, 1, 2);

-- Insert data into ITEM table
INSERT INTO ITEM VALUES (1, 50);
INSERT INTO ITEM VALUES (2, 30);
INSERT INTO ITEM VALUES (3, 25);
INSERT INTO ITEM VALUES (4, 40);
INSERT INTO ITEM VALUES (5, 60);

-- Insert data into SHIPMENT table
INSERT INTO SHIPMENT VALUES (1, 1, TO_DATE('2023-01-05', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT VALUES (2, 2, TO_DATE('2023-02-10', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT VALUES (3, 1, TO_DATE('2023-03-15', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT VALUES (4, 3, TO_DATE('2023-04-20', 'YYYY-MM-DD'));
INSERT INTO SHIPMENT VALUES (5, 2, TO_DATE('2023-05-25', 'YYYY-MM-DD'));

-- Insert data into WAREHOUSE table
INSERT INTO WAREHOUSE VALUES (1, 'City1');
INSERT INTO WAREHOUSE VALUES (2, 'City2');
INSERT INTO WAREHOUSE VALUES (3, 'City3');
