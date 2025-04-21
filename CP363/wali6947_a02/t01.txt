SELECT 
    CONCAT(member.memberSurname, ' ', member.memberForename) AS fullName,
    pt.pubTypeDesc AS publicationType,
    p.pubTitle AS publicationTitle
FROM 
    member 
JOIN 
    pub p ON member.memberId = p.pubMemberId
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
ORDER BY 
    fullName, 
    publicationType, 
    publicationTitle;
