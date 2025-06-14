// publicationsData.js
const publications = [
    { titre: "Intelligence Artificielle et Avenir", auteur: "Koudil Mouloud", datePublication: new Date(2023, 5, 15), nombrePages: 250, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "EIAH" },
    { titre: "Optimisation des Réseaux Neuronaux", auteur: "Annane Mohammed", datePublication: new Date(2022, 10, 7), nombrePages: 320, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "OPT" },
    { titre: "Apprentissage Machine et Applications", auteur: "Si Tayeb Fatima", datePublication: new Date(2024, 2, 20), nombrePages: 180, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "non actif", equipe: "MSI" },
    { titre: "Big Data et Santé", auteur: "Sadeg Souhila", datePublication: new Date(2020, 8, 10), nombrePages: 290, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "SURES" },
    { titre: "Blockchain et Cybersécurité", auteur: "Kermi Adel", datePublication: new Date(2019, 11, 5), nombrePages: 400, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "CoDesign" },
    { titre: "Data Science et Son Impact", auteur: "Hidouci Khaled Walid", datePublication: new Date(2022, 3, 19), nombrePages: 210, type: "livre", qualiteChercheur: "Doctorant", statutChercheur: "actif", equipe: "TNS" },
    { titre: "Méthodes Avancées en Machine Learning", auteur: "Zegour Djamel Eddine", datePublication: new Date(2021, 7, 21), nombrePages: 270, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "AI4ALL" },
    { titre: "Computational Intelligence", auteur: "Koudil Mouloud", datePublication: new Date(2018, 11, 4), nombrePages: 350, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "Optimus" },
    { titre: "Les Réseaux de Neurones Profonds", auteur: "Annane Mohammed", datePublication: new Date(2017, 9, 15), nombrePages: 280, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "EIAH" },
    { titre: "Analyse de Données Massives", auteur: "Si Tayeb Fatima", datePublication: new Date(2023, 1, 23), nombrePages: 320, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "BigDataX" },
    { titre: "IoT et Smart Cities", auteur: "Sadeg Souhila", datePublication: new Date(2020, 6, 5), nombrePages: 300, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "InnovateTech" },
    { titre: "Cryptographie et Sécurisation des Réseaux", auteur: "Kermi Adel", datePublication: new Date(2019, 8, 14), nombrePages: 240, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "non actif", equipe: "SecureNet" },
    { titre: "AI et la Recherche Médicale", auteur: "Hidouci Khaled Walid", datePublication: new Date(2022, 4, 30), nombrePages: 260, type: "livre", qualiteChercheur: "Doctorant", statutChercheur: "actif", equipe: "MedTech" },
    { titre: "Blockchain et Innovation", auteur: "Zegour Djamel Eddine", datePublication: new Date(2021, 11, 12), nombrePages: 310, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "CoDesign" },
    { titre: "Systèmes d'Apprentissage Profond", auteur: "Koudil Mouloud", datePublication: new Date(2022, 2, 15), nombrePages: 230, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "DeepMind" },
    { titre: "Algorithmes et Programmation", auteur: "Annane Mohammed", datePublication: new Date(2019, 5, 9), nombrePages: 280, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "AI Research" },
    { titre: "Génie Logiciel et IA", auteur: "Si Tayeb Fatima", datePublication: new Date(2024, 7, 11), nombrePages: 300, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "AI Tech" },
    { titre: "Introduction aux Systèmes Embarqués", auteur: "Sadeg Souhila", datePublication: new Date(2021, 6, 2), nombrePages: 290, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "Embedded Systems" },
    { titre: "Apprentissage Renforcé et Applications", auteur: "Kermi Adel", datePublication: new Date(2020, 1, 18), nombrePages: 260, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "non actif", equipe: "ReinforceAI" },
    { titre: "Réseaux de Neurones et Optimisation", auteur: "Hidouci Khaled Walid", datePublication: new Date(2022, 8, 12), nombrePages: 330, type: "livre", qualiteChercheur: "Doctorant", statutChercheur: "actif", equipe: "DeepLab" },
{ titre: "Technologies Émergentes", auteur: "Zegour Djamel Eddine", datePublication: new Date(2021, 3, 14), nombrePages: 240, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "EmergingTech" },
{ titre: "Informatique Quantique et Algorithmes", auteur: "Koudil Mouloud", datePublication: new Date(2019, 12, 8), nombrePages: 310, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "QuantumComputing" },
{ titre: "Vision par Ordinateur", auteur: "Annane Mohammed", datePublication: new Date(2024, 11, 22), nombrePages: 270, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "VisionTech" },
{ titre: "Technologies Mobiles et IoT", auteur: "Si Tayeb Fatima", datePublication: new Date(2023, 0, 19), nombrePages: 320, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "MobileTech" },
{ titre: "Systèmes Distribués et Réseaux", auteur: "Sadeg Souhila", datePublication: new Date(2020, 2, 5), nombrePages: 350, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "DistributedSystems" },
{ titre: "Blockchain et Applications Financières", auteur: "Kermi Adel", datePublication: new Date(2021, 7, 11), nombrePages: 260, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "FinanceTech" },
{ titre: "Bioinformatique et Intelligence Artificielle", auteur: "Hidouci Khaled Walid", datePublication: new Date(2022, 5, 30), nombrePages: 300, type: "livre", qualiteChercheur: "Doctorant", statutChercheur: "actif", equipe: "BioTech" },
{ titre: "Deep Learning et Vision par Ordinateur", auteur: "Zegour Djamel Eddine", datePublication: new Date(2019, 10, 16), nombrePages: 280, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "ComputerVision" },
{ titre: "Réseaux de Calcul et Cloud", auteur: "Koudil Mouloud", datePublication: new Date(2021, 4, 12), nombrePages: 290, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "CloudTech" },
{ titre: "Technologies de l'Information et Sécurité", auteur: "Annane Mohammed", datePublication: new Date(2022, 8, 1), nombrePages: 250, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "InfoSec" },
{ titre: "Éthique de l'Intelligence Artificielle", auteur: "Si Tayeb Fatima", datePublication: new Date(2020, 9, 30), nombrePages: 230, type: "conférence", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "non actif", equipe: "EthicsAI" },
{ titre: "Systèmes Intelligents pour la Santé", auteur: "Sadeg Souhila", datePublication: new Date(2019, 6, 18), nombrePages: 300, type: "livre", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "HealthTech" },
{ titre: "Apprentissage Machine Avancé", auteur: "Kermi Adel", datePublication: new Date(2021, 11, 5), nombrePages: 220, type: "journal", qualiteChercheur: "Enseignant-Chercheur", statutChercheur: "actif", equipe: "AdvancedML" },
{ titre: "Big Data pour l'Industrie", auteur: "Hidouci Khaled Walid", datePublication: new Date(2024, 9, 15), nombrePages: 270, type: "livre", qualiteChercheur: "Doctorant", statutChercheur: "actif", equipe: "IndustrialData" },

    
];

export default publications;
