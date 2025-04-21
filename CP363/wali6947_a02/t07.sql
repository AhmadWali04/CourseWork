SELECT 
    pt.pubTypeDesc AS fullPublicationType,
    COUNT(p.pubId) AS numberOfPublications
FROM 
    pub p
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
GROUP BY 
    pt.pubTypeDesc
ORDER BY 
    fullPublicationType
